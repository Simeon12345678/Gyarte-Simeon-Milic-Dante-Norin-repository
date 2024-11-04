package Algorithms.Algorithm1Java;

import java.util.ArrayList;
import java.util.List;
import java.util.Collections;
import java.util.Random;

/**
 * IntroSort
 */
public class IntroSort {
    // creates the array
    static List<Integer> createArray(int size) {
        Random rand = new Random();
        List<Integer> arr = new ArrayList<Integer>();
        for (int i = 0; i < size - 1; i++) {
            arr.add(rand.nextInt(1000 + 1));
        }
        return arr;
    }
    public static void main(String[] args) {
        List<Integer> arr = createArray(10);

        // the sorting
        Collections.sort(arr);

        System.out.println("Sorted array: " + arr);
    }
}