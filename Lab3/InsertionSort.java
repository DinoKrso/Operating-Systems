package org.example;

public class InsertionSort{

    public static boolean less(int v, int w) {
        return v < w;
    }
    public static void swap (int[] elements, int a, int b) {
        int tmp = elements[a];
        elements[a] = elements[b];
        elements[b] = tmp;
    }
    public static void sort(int[] elements) {
        for (int i = 0; i < elements.length; i++) {
            for (int j = i; j > 0; j--) {
                if (less(elements[j], elements[j - 1])) {
                    swap(elements, j, j - 1);
                } else {
                    break;
                }
            }
        }
    }

}