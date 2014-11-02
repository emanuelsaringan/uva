import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    List<String> nums = new ArrayList<String>();
    int N = in.nextInt();
    while (N != 0) {
      for (int i = 0; i < N; i++) {
        nums.add(in.next());
      }

      Collections.sort(nums, new Comparator<String>() {
        public int compare(String a, String b) {
          int aLen = a.length();
          int bLen = b.length();
          int i = 0;
          int j = 0;

          while (i < aLen && j < bLen) {
            if (a.charAt(i) != b.charAt(j)) {
              return (b.charAt(j) - '0') - (a.charAt(i) - '0');
            }

            i++;
            j++;
          }

          if (aLen > bLen) {
            return this.compare(a.substring(b.length()), b);
          }

          if (aLen < bLen) {
            return this.compare(a, b.substring(a.length()));
          }

          return 0;
        }
      });

      printNums(nums);

      N = in.nextInt();
      nums.clear();
    }
  }

  private static final void printNums(List<String> nums) {
    for (String num : nums) {
      System.out.print(num);
    }

    System.out.println();
  }
}
