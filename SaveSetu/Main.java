import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    String command = null;
    long total = 0L;
    while (T-- > 0) {
      command = in.next();
      if ("donate".equals(command)) {
        total += in.nextInt();
      } else if ("report".equals(command)) {
        System.out.println(total);
      } else {
        throw new IllegalArgumentException("invalid command: " + command);
      }
    }
  }
}
