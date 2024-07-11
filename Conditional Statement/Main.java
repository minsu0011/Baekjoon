//https://www.acmicpc.net/problem/2525
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Main{
    public static int hour;
    public Main(){
        hour = 0;
    }
    public static int getHour(int m){
        if(m < 60) return m;
        else{
            hour ++;
            return getHour(m - 60);
        }
    }
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Main ov = new Main();
        int a, b;
        int c;
        int m;
        int h;
        StringTokenizer st = new StringTokenizer(br.readLine());
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(br.readLine());
        m = b + c;
        m = ov.getHour(m);
        h = ov.hour + a;
        if(h >= 24)
            h = h - 24;
        System.out.println(h + " " + m);
        br.close();
    }
}