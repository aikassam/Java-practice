/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.processingelementrenamer;

/**
 *
 * @author jacob
 */
import java.util.List;

public class ProcessingElementRenamer {
    public static void rename(List<String> entries, String suffix) {
        for (int i = 0; i < entries.size(); i++) {
            String entry = entries.get(i);
            int dotIndex = entry.lastIndexOf('.');
            if (dotIndex == -1) {
                entries.set(i, entry + suffix);
            } else {
                String baseName = entry.substring(0, dotIndex);
                String extension = entry.substring(dotIndex);
                entries.set(i, baseName + suffix + extension);
            }
        }
    }
}
