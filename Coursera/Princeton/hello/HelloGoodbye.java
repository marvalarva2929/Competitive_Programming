/* *****************************************************************************
 *  Name:              Ada Lovelace
 *  Coursera User ID:  123456
 *  Last modified:     October 16, 1842
 **************************************************************************** */

public class HelloGoodbye {
    public static void main(String[] args) {
        String name1 = args[0];
        String name2 = args[1];
        System.out.println(String.format("Hello %s and %s.", name1, name2));
        System.out.println(String.format("Goodbye %s and %s.", name2, name1));
    }
}
