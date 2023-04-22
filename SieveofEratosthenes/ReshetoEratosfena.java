import java.util.ArrayList;
import java.util.Arrays;

public class ReshetoEratosfena {
    private static boolean[] AllNumbers;
    private static int[] EndResult;
    private static int size;

    public ReshetoEratosfena(int size) {
        ReshetoEratosfena.size = size;
        if(size < 2 ) ShowArray();
        else {
            GenerateBooleanArray();
            CrossOutMultiples();
            ConvertResultIntoArray();
            ShowArray();
        }
    }
    public static void GenerateBooleanArray(){
        AllNumbers = new boolean[size + 1];
        for (int i = 2; i < AllNumbers.length; i++)
            AllNumbers[i] = false;
    }
    public static void CrossOutMultiples(){
        int limit = SetLimit();
        for (int i = 2; i < limit; i ++)
            if(CheckCrossedNum(i))
                ExpongeNumbers(i);
    }
    public static int SetLimit(){
        double limit = Math.sqrt(AllNumbers.length);
        return (int)limit;
    }
    public static boolean CheckCrossedNum(int i){
        return !AllNumbers[i];
    }
    public static void ExpongeNumbers(int i){
        for (int multiple = i * 2; multiple < AllNumbers.length; multiple += i)
            AllNumbers[multiple] = true;
    }
    public static void ConvertResultIntoArray(){
        EndResult = new int[NumberOfUncrossedNumbers()];
        for (int i = 2, j = 0; i < AllNumbers.length; i ++)
            if(CheckCrossedNum(i))
                EndResult[j++] = i;
    }
    public static int NumberOfUncrossedNumbers(){
        int counter = 0;
        for (int i = 2; i < AllNumbers.length; i++)
            if(CheckCrossedNum(i)) counter++;
        return counter;
    }
    public static void ShowArray(){
        if(EndResult.length == 0) System.out.println("Pip");
        else System.out.println(Arrays.toString(EndResult));
    }
}
