import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static String next() throws IOException{
        while(st == null || !st.hasMoreTokens()){
            String line = br.readLine();
            if(line == null) return null;
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public static void main(String[] args) throws Exception {
        String str = next();
        String bomb = next();
        
        char[] bombChars = bomb.toCharArray();

        StringBuilder sb = new StringBuilder();
        
        int pos=0, m=bomb.length();
       
        while(pos<str.length()){
            sb.append(str.charAt(pos));
            pos++;
            if(sb.length() >= m){
                boolean ok = true;
                for(int j=0; j<m; j++){
                    if(sb.charAt(sb.length()-m+j) != bombChars[j]){
                        ok = false;
                        break;
                    }
                }
                if(ok) sb.setLength(sb.length()-m);
            }
            
        }
        if(sb.length()==0) System.out.println("FRULA"); 
        else System.out.println(sb);
    }
}
