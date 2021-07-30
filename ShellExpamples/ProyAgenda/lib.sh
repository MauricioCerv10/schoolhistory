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
	echo "Tecle el numero de la opcion que desea seleccionar"
	read numOpc
	echo $numOpc | grep "^[0-9][0-9]*$"

	if [ $? -eq "0" ]
	then
  		statement when number
	else 
  		statement when char
	fi
	
	cont=1	
	#en la busqueda del grep, buscamos la opcion que desea seleccionar
	encontrado=0
	for i in ${resultSearch}
	do
		if [ ${cont} -eq ${numOpc} ]; then
			opcSelect=${i}
		fi
		cont=$((cont+1))
	done
	#despues de validar un numero probar un grep aqui para reeemplazar el campo por algo
	return 0
}
