package com.hellosanket;

import java.net.Inet4Address;
import java.net.InterfaceAddress;
import java.util.HashMap;
import java.util.Map;
import java.util.zip.CheckedInputStream;

/**
 * Find the first non-repeated char in a given string:
 * Example input: Sister
 * output: i
 *
 * input: teeter
 * output: r
 *
 */
public class Main {

    /**
     * Generates a hashmap with character as key
     *
     *
     * @param input
     * @return
     * @throws IllegalArgumentException
     */
    public static HashMap<Character, Integer> generateMap(final String input) throws IllegalArgumentException {

        // Always null check input
        if (input == null) throw new IllegalArgumentException();

        // Locally convert to lower case
        final String sanitized = input.toLowerCase();

        final Map map = new HashMap<Character, Integer>();

        for (int i = 0; i < input.length(); i++) {
            Character c = (Character) sanitized.charAt(i);
            try {
                Integer val = (Integer) map.get(c);
                if (val == null) {
                    map.put(c,1);
                } else if (val == 1) {
                    map.put(c,2);
                } else {
                    // do nothing...don't care if more than 2
                }
            } catch (StringIndexOutOfBoundsException e) {
                e.printStackTrace();
            } catch (NullPointerException e) {
                e.printStackTrace();
            } catch (ClassCastException e) {
                e.printStackTrace();
                Thread.currentThread().interrupt();
            }
        }

        return (HashMap<Character, Integer>) map;
    }

    public static Character getFirstUnique(final Map map, final String input) {

        for (int i = 0; i < input.length(); i++) {
            char c = (Character) input.charAt(i);
            final Character cc = new Character(Character.toLowerCase(c));
            if (map.get(cc) == 1) {
                return cc;
            }
        }
        return null;
    }

    //public static find
    public static void main(String[] args) {
        String s = "Teeter";
        Map m = generateMap(s);
        System.out.println("Found unique letter: " + getFirstUnique(m, s));

        s = "Sister";
        m = generateMap(s);
        System.out.println("Found unique letter: " + getFirstUnique(m, s));
    }
}
