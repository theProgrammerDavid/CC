package prep.practice;

/**
 * replaceSpace
 */

public class replaceSpace {

    public static String replaceSpaceInString(String s) {
        int count = 0;
        int slow = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ')
                count++;
        }

        final int newLen = s.length() + count * 2;
        char str[] = new char[newLen];

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') {
                str[slow++] = '%';
                str[slow++] = '2';
                str[slow++] = '0';

            } else {
                str[slow++] = s.charAt(i);
            }
        }
        return new String(str);
    }

    public static void main(String[] args) {
        String s1 = "Hello World my name is jack";
        System.out.println(s1);
        System.out.println(replaceSpaceInString(s1));
    }
}