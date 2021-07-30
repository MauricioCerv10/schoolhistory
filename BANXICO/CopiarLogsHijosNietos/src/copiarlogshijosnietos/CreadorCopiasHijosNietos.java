/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package copiarlogshijosnietos;

import java.io.File;
import java.io.FileFilter;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author T43705
 */
public class CreadorCopiasHijosNietos {
   
    public void copiaArchivos(String[] directorios, String pathSalida,String fechaIni,String fechaFin){
        for(int i = 0; i<directorios.length;i++){
            String subDirOrigen = directorios[i]; 
            /*Creamos un objeto SimpleDateFormat para transformar Strings a un objeto Date
            y poder hacer la comparación de fechas */
            SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");

            /*Verificamos que la fecha de inicio no exceda la fecha de fin*/
            try {
                if( sdf.parse( fechaIni ).after( sdf.parse(fechaFin) ) ){
                    System.out.println("[ERROR]: La fecha de inicio es mayor a la fecha de Fin");
                    return;
                }
            } catch (ParseException ex) {
                System.out.println("[ERROR]: Formato incorrecto de la fecha");
                Logger.getLogger(CreadorCopiasHijosNietos.class.getName()).log(Level.SEVERE, null, ex);
            }

            /*Creamos un objeto FileManager que nos ayudara a obtener nuestra lista de archivos que
            necesitamos, para copiarlos ala ruta de destino*/
            FileManager fm = new FileManager();
            File[] archivos = fm.obtieneArchivos(subDirOrigen, fechaIni, fechaFin);
            int archCopiados = 0;
            
            if (archivos == null || archivos.length == 0) {
                System.out.println("[WARNING]: No hay elementos dentro de la carpeta especificada");
                return;
            }
            else {
                System.out.println("[ARCHIVOS OBTENIDOS]: "+ archivos.length);
                System.out.println("[SUBDIRECTORIO ORIGEN] :"+subDirOrigen);
                System.out.println("COPIANDO...");
                for (int j=0; j< archivos.length; j++) {
                    File archivo = archivos[j];
                    /* System.out.println(String.format("%s - %s", 
                                                      archivo.getName(), 
                                                      sdf.format(archivo.lastModified())
                                                      ));*/
                    if(fm.crearCopiaDeArchivos(archivo,subDirOrigen,pathSalida)) archCopiados++;
                }
                /*Copiamos los archivos obtenidos al subdirectorio especificado en pathSalida*/
                System.out.println(archCopiados+" de "+archivos.length+" archivos copiados en : " +pathSalida+"\n");
            }
        }
        System.out.println("Proceso terminado\n");
    }
}
