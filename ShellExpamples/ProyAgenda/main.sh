#!/bin/sh

. ./lib2.sh

echo "Welcome to your Agenda"
echo "Please enter the action you want to perform"
echo "1.Add record"
echo "2.Edit record"
echo "3.Remove record"

read action

if [ ${action} -eq "1" ]
then
	echo "Ingrese el nombre que quiere agregar"
	read nombre
	#TODO quitar espacios al nombre
	echo "Ingrese el numero de telefono"
	read telefono
	echo "Ingrese la dirección de correo"
	read correo
	echo "¿Desea agregar el siguiente contacto?(si/no)"
	echo "Nombre:${nombre}"
	echo "Telefono:${telefono}"
	echo "Correo:${correo}"
	read confirm
	valido=0
	#Verificamos la confirmación de añadir contacto.
	#Iteramos hasta conseguir una de las dos opciones validas
	while [ ${valido} -eq "0" ]
	do
		if [ "$confirm" = "si" ]; then
			campo=${nombre}":"${telefono}":"${correo} # formato para insertar en el records.txt
			campo=`echo "$campo" | tr ' ' '_'` #reemplazamos espacios por guiones bajos
			res=$?
			add_record ${campo} records.txt # añadimos el campo a nuestro txt
			if [ ${res} -eq "0" ]; then
				echo "Contacto añadido exitosamente"
				valido=1 # le damos valor de 1 a la bandera indicando que se completo la acción de inserción
			fi
		elif [ "confirm" = "no"]; then
			echo "Contacto no añadido"
			valido=1
		else 
			echo "Opcion no valida, ingrese de nuevo "
		fi
	done
elif [ ${action} -eq "2" ]
then
	echo "Ingrese el nombre que quiere editar"
	read nombre
	echo "Buscando ${nombre} en agenda..."
	search_records ${nombre}
	echo ${opcSelect}
	
	#Tomamos el nombre, correo y numero por separado, para poder editar
	nombreEdit=`echo ${opcSelect} | cut -d: -f1`
	numeroEdit=`echo ${opcSelect} | cut -d: -f2`
	correoEdit=`echo ${opcSelect} | cut -d: -f3`
	echo "${nombreEdit} ${numeroEdit} ${correoEdit}"
	seguir=0
	while : 
	do
		echo "¿Qué campo desea modificar?"
		echo "[1] Nombre"
		echo "[2] Numero"
		echo "[3] Correo"
		read inputS
		case $inputS in
			1)
				echo "Ingrese el nuevo nombre"
				read nombreNuevo
				#Llamamos a la función que editara el archivo, con el nuevo nombre,  el correo y  el numero quedan intactos 
				#El ultimo parametro es el campo completo que queremos cambiar dentro del archivo
				nombreNuevo=`echo ${nombreNuevo} | tr ' ' '_'`
				nombreEdit=${nombreNuevo}
				intercambiaCampos ${nombreEdit} ${numeroEdit} ${correoEdit} ${opcSelect}
				
		
				#Ejecutar IF por si quiere seguir editando el campo
				echo "¿Desea seguir editando el registro? si/no"
				read decision
				if ! [ ${decision} = "si" ]; then
					break
				fi
				;;
			2)
				while :
				do
					echo "Ingrese el numero nuevo"
					read numeroNuevo
					echo $numeroNuevo | grep "^[0-9][0-9]*$"
					if [ $? -eq "0" ]; then
						break
					else 
						echo "Formato invalido"
					fi

				done
				numeroEdit=${numeroNuevo}
				intercambiaCampos ${nombreEdit} ${numeroEdit} ${correoEdit} ${opcSelect}
				
				#Ejecutar IF por si quiere seguir editando el campo
				echo "¿Desea seguir editando el registro? si/no"
				read decision
				if ! [ ${decision} = "si" ]; then
					break
				fi
				;;
			3)	
				echo "Ingrese el nuevo correo"
				read correoNuevo
				correoEdit=${correoNuevo}
				#Llamamos a la función que editara el archivo, con el nuevo nombre,  el correo y  el numero quedan intactos 
				#El ultimo parametro es el campo completo que queremos cambiar dentro del archivo
				intercambiaCampos ${nombreEdit} ${numeroEdit} ${correoEdit} ${opcSelect}
				
		
				#Ejecutar IF por si quiere seguir editando el campo
				echo "¿Desea seguir editando el registro? si/no"
				read decision
				if ! [ ${decision} = "si" ]; then
					break
				fi
				;;

			 *) 
				echo "Opcion no vaida, ingrese de nuevo"
				;;
		esac
	done
elif [ ${action} -eq "3" ]
then
	echo "Ingrese el nombre que quiere eliminar"
	read nombre
	echo "Buscando ${nombre} en agenda..."
	search_records ${nombre}
	echo ${opcSelect}
	sed -i "s/$opcSelect//g" "records.txt"
else
	echo "Ingrese una opción valida"
fi
