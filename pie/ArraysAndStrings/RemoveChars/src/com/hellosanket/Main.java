package com.hellosanket;

public class Main {
    public static final int[] buildArray(final String src) {
        // true means character is to be removed
        int [] arr = new int[128];
        final String lowered = src.toLowerCase();
        for (int i = 0; i < lowered.length(); i++) {
            arr[lowered.charAt(i)] = 1;

        }

//        StringBuilder sb = new StringBuilder();
//        for (int i =0 ; i < arr.length; i++) {
//            sb.append(arr[i]);
//            sb.append(",");
//        }
//        System.out.println(sb.toString());

        return arr;
    }

    public static final String removeChars(final String src, final String rem) {
        int[] arr = buildArray(rem);
        final String lowered = src.toLowerCase();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < lowered.length(); i++) {
            if (arr[lowered.charAt(i)] != 1) {
                sb.append(lowered.charAt(i));
//                System.out.println("append " + lowered.charAt(i));
            }
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        final String s = "Hello to A WOrld so big!";
        System.out.println("Src = " + s + "\nFinal string = " + removeChars(s, "eiou"));
    }
}
