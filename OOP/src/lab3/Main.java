package lab3;
public class Main {
    public static void main(String[] args) {
        int hr;
        int min;
        int sec;
        int[] temp;
        Time currTime = new Time(0,0,0);
        temp = currTime.getTime();
        hr = temp[0];
        min = temp[1];
        sec = temp[2];
        System.out.println(
                "The initial military time is set to: "
                        + hr + ":" + min + ":" + sec
        );
        currTime.setTime(23, 59, 59);
        temp = currTime.getTime();
        hr = temp[0];
        min = temp[1];
        sec = temp[2];
        System.out.println(
                "Поточний встановлений час: "
                        + hr + ":" + min + ":" + sec
        );
        currTime.incrementTime();
        temp = currTime.getTime();
        hr = temp[0];
        min = temp[1];
        sec = temp[2];
        System.out.println(
                "Після інкременту часу, поточний час: "
                        + hr + ":" + min + ":" + sec
        );
    }
}