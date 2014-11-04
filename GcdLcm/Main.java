import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    for (int i = 0; i < T; i++) {
      int G = in.nextInt();
      int L = in.nextInt();

      if (L % G != 0) {
        System.out.println(-1);
      } else {
        System.out.println(G + " " + L);
      }
    }
  }
}
