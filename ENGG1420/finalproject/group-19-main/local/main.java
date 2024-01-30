/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package entry2;

/**
 *
 * @author smpat
 */
public class main {

    
    public static void main(String[] args) {
        Entry2 localEntry = new Entry2("c:\\sample\\txt\\addresses.txt");
        Entry2 remoteEntry = new Entry2("r-34w6", 12345);
        
        System.out.println(localEntry); // prints "c:\sample\txt\addresses.txt"
        System.out.println(remoteEntry); // prints "(r-34w6, 12345)"
        System.out.println(remoteEntry.getRepoId()); // prints "r-34w6"
        System.out.println(remoteEntry.getEntryId()); // prints 12345
    }
}
