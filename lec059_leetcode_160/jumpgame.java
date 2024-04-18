public class jumpgame{
    public static boolean canjump(int arr[]){



        int final_pos = arr.length-1;

        for(int i = arr.length -2;i>=0;i--){
            if(arr[i]+i>=final_pos){
                final_pos=i;
            }
        }
        return final_pos==0;
    }
    public static void main(String args[]) {
        int arr[] = {2,3,1,1,4};
        if(canjump(arr)==true){
            System.out.println("yes");
        }else{
            System.out.println("no");
        }

    }
}