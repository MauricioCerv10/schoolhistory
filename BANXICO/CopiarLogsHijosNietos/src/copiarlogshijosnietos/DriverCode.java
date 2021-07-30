/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package copiarlogshijosnietos;

/**
 *
 * @author T43705
 */
public class DriverCode {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        CreadorCopiasHijosNietos copiar = new CreadorCopiasHijosNietos();
        String[] directorios = {args[0]};
        copiar.copiaArchivos(directorios,args[1], "07/01/2020 00:00:00", "15/02/2020 17:00:00");
        
    }
    
}
