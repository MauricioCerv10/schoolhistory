#!/bin/sh

add_record(){
	recorParam=$1
	archivo=$2
	if [ ! -e ${archivo} ]; then
		echo "El archivo ${archivo} no existe"
		res=1
		return ${res}
	fi
	echo ${recorParam} >> records.txt
	returnCode=$?
	if [ ${returnCode} -ne "0" ]; then
		echo "Error al añadir nuevo contacto"
		res=2
		return ${res}
	fi
	res=0
	return ${res}
}
search_records(){
	keyWord=$1
	echo "Recibí ${keyWord}"
	resultSearch=`grep -i ${keyWord} records.txt`
	returnCode=$?
        if [ ${returnCode} -ne "0" ]; then
                echo "Error en la busqueda dentro del archivo"
                return 1
        fi
	
	#TODO iterar sobre el resultado del grep, mostrar nombre(quitar guiones bajos) correo, numero
	#TODO comentar codigo
	cont=1
	for i in ${resultSearch}
	do
		nombre=`echo ${i} | cut -d: -f1`
		nombre=`echo ${nombre} | tr '_' ' '`
		numero=`echo ${i} | cut -d: -f2`
		correo=`echo ${i} | cut -d: -f3`
		echo "[${cont}] Nombre: ${nombre} \011 Correo: ${correo} \011 Numero: ${numero}"
		cont=$((cont+1))
	done
	validado=1
	while [ ${validado} -eq "1" ]
	do
		echo "Tecle el numero de la opcion que desea seleccionar"
		read numOpc
		echo $numOpc | grep "^[0-9][0-9]*$"
		if [ $? -eq "0" ] && [ ${numOpc} -lt ${cont} ] && [ ${numOpc} -gt "0" ]
		then
  			validado=0
		else 
			echo "Opción no valida"
		fi
	done
	cont=1	
	#en la busqueda del grep, buscamos la opcion que desea seleccionar
	encontrado=0
	for i in ${resultSearch}
	do
		if [ ${cont} -eq ${numOpc} ]; then
			opcSelect=${i}
			echo "Encontrado: ${opcSelect}"
		fi
		cont=$((cont+1))
	done
	echo "Cadena a cambiar: ${opcSelect}"
	#despues de validar un numero probar un sed aqui para reeemplazar el campo por algo
	return 0
}

intercambiaCampos(){
	nombre=${1}
	numero=${2}
	correo=${3}
	campoEdita=${4}
	echo "nombre: ${1}"
	echo "numero: ${2}"
	echo "correo: ${3}"
	echo "campoEdita: ${4}"
	#Formamos el nuevo campo, concatenando la nueva variable que nos pasen con las ya existentes
	campoNuevo=${nombre}":"${numero}":"${correo}
        #Editamos  el archivo con un sed, reemplazando el campo que existia con el nuevo que tenemos
	sed -i "s/$campoEdita/$campoNuevo/g" "records.txt"
	echo "Campo editable  ${campoEdita}"
	opcSelect=${campoNuevo}
}
