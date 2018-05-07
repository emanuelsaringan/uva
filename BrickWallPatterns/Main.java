import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    long[] arr = new long[51];
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3; i <= 50; i++) {
      arr[i] = arr[i - 1] + arr[i - 2];
    }
    int length = in.nextInt();
    while (length != 0) {
      System.out.println(arr[length]);
      length = in.nextInt();
    }
  }
}
