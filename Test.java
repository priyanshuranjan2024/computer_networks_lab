import java.util.*;

public class Test{

    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt(); //size of the matrix

        int[][] arr=new int[n][n];
        //taking input
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j]=sc.nextInt();

            }
        }

        int pdSum=0;
        for(int i=0;i<n;i++){
            pdSum+=arr[i][i];
        }

        int sdSum=0;
        int row=0;
        int col=n-1;

        while(row<n && col>=0){
            sdSum+=arr[row][col];
            row++;
            col--;
        }



        if(n%2==0){
            System.out.println(pdSum+sdSum);
        }else{
            int index=n/2;
            System.out.println(pdSum+sdSum-arr[index][index]);
        }

        sc.close();


    }

    
}