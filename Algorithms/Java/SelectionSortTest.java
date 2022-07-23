import java.util.*;
import java.util.Scanner;  // Import the Scanner class


public class SelectionSortTest {
    public static Object SelectionSort(int[] list, Boolean cnt){
        int count = 0;

        for(int i = 0; i<list.length; i++){
            int min = (int) Math.pow((double)2,(double)32);
            int min_index = -1;

            int k = list[i];

            for(int j=i; j<list.length; j++){
                if(list[j]<min){
                    min = list[j];
                    min_index = j;
                    count += 1;
                }
            }

            list[i]=min;
            list[min_index]=k;
        }

        if(cnt==false){
            return list;
        } else{
            return count;
        }
    }

    public static int[] generateRandomArray(int n){
        int[] list = new int[n];
        
        Random random = new Random();
        
        for (int i = 0; i < n; i++)
        {
            list[i]=(int)Math.floor(Math.random()*(1000-(-1000)+1)+(-1000));
        }

       return list;
    } 

    public static void SelectionSortAnalysis(){
        Scanner myObj = new Scanner(System.in);  // Create a Scanner object
        System.out.println("How big do you want your test array? ");
        int n = myObj.nextInt();

        int count1 = (int) SelectionSort(generateRandomArray(n),true);
        int count2 = (int) SelectionSort(generateRandomArray(2*n),true);

        System.out.println("Sorting a list of size " + n + " took " + count1 + " steps.");
        System.out.println("Sorting a list of size " + 2*n + " took " + count2 + " steps.");
        System.out.println("That means that doubling the size of the list required " + (double)count2/(double)count1 + " times longer."); 

        myObj.close();
    }

    public static void main (String[] args){
        int[] test = (int[])SelectionSort(new int[]{64,25,12,22,11},false);

        System.out.println(Arrays.toString(test));

        SelectionSortAnalysis();

    }
}
