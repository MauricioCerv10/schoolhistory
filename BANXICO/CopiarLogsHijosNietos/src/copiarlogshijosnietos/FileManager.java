/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package copiarlogshijosnietos;

import java.io.File;
import java.io.FileFilter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author T43705
 */
public class FileManager {
    public File[] obtieneArchivos(String subDirOrigen,String fechaIni,String fechaFin){
        /*Obtenemos la carpeta de donde extraeremos los archivos*/
        File carpeta = new File(subDirOrigen);
        
        /*Creamos un filtro que nos ayudará a obtener los archivos que se encuentren 
        dentro de nuestra fecha de inicio y fecha de fin*/
        FileFilter filtro = new FileFilter() {
          @Override
          public boolean accept(File arch) {
              SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");  
              try {
                  if(sdf.parse(fechaIni).before(new Date(arch.lastModified())) && sdf.parse(fechaFin).after(new Date(arch.lastModified()))){
                      return true;
                  }else{
                      return false;
                  }

              } catch (ParseException ex) {
                  System.out.println("[ERROR]: La fecha de inicio es mayor a la fecha de Fin");
                  Logger.getLogger(CreadorCopiasHijosNietos.class.getName()).log(Level.SEVERE, null, ex);
              }
              return false;
          }
        };
        /*Pasamos como parametro el filtro y obtenemos nuestra lista de archivos*/
        return carpeta.listFiles(filtro);
    }
    public boolean crearCopiaDeArchivos(File archivo,String rutaOrigen, String rutaSalida){
        /*Iteramos através de todos los archivos para crear una copia 
        dentro de la carpeta especificada en rutaSalida*/
        if(archivo.isDirectory()){
            //find /users/a10212/Mauricio/pruebasComandoFind/ -type f -iname '*.kis' -exec cp {} /users/a10212/Mauricio/salidapruebasComandoFind \;
            try {
                String [] cmd = {"find",rutaOrigen,"-type", "f","-iname","'*.kis'","-exec","cp","{}",rutaSalida,"\\;"}; //Comando de apagado en windows
                Runtime.getRuntime().exec(cmd);
            } catch (IOException ioe) {
                System.out.println ("[ERROR]: Fallo al ejecutar el comando");
            }
        }else{
            InputStream inputStream = null;
            OutputStream outputStream = null;

            try {

                File archivoCopia = new File(rutaSalida+archivo.getName());
                inputStream = new FileInputStream(archivo);
                outputStream = new FileOutputStream(archivoCopia);
                byte[] buffer = new byte[1024];
                int length;

                while ((length = inputStream.read(buffer)) > 0) {
                    outputStream.write(buffer, 0, length);
                }

                inputStream.close();
                outputStream.close();

                System.out.println("Archivo "+archivo.getName()+" copiado");
            } catch (IOException e) {
                System.out.println("[ERROR]: No se pudo copiar el archivo "+archivo.getName());
                return false;
            }
        }
        return true;
        
    }
    
}
