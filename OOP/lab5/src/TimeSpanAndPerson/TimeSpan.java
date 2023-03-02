package TimeSpanAndPerson;

public class TimeSpan {
    private int hours;
    private int minutes;

    public TimeSpan() {
       this.hours = 0;
       this.minutes = 0;
    }
    public TimeSpan(int minutes) {
        if (minutes < 0 || minutes >= 60)
            return;

        this.minutes = minutes;
    }
    public TimeSpan(int hours, int minutes) {

        if (minutes < 0 || minutes >= 60 || hours < 0)
            return;

        this.hours = hours;
        this.minutes = minutes;

    }

    public int getHours() {
        return hours;
    }

    public int getMinutes() {
        return minutes;
    }

    public void add(int hours, int minutes) {

        if (minutes < 0 || minutes >= 60 || hours < 0)
            return;

        this.hours = this.hours + minutes;
        this.minutes = this.minutes + minutes;

    }

    public void addMinutes(int minutes) {
        add(0, minutes);
    }

    public void addTimeSp(TimeSpan timeSpan) {
        add(timeSpan.getHours(), timeSpan.getMinutes());
    }

    public double getTotalHours() {

        if (hours < 0 && minutes < 0)
            return 0;

        if (minutes <= 59)
            return (double) (hours * 60 + minutes) / 60;

        return 0;

    }

    public int getTotalMinutes() {

        if (hours < 0 && minutes < 0)
            return 0;

        return minutes + (60 * hours);

    }

    public void subtract(int hours, int minutes) {
        this.hours = this.hours - hours;
        this.minutes = this.minutes - minutes;

        if (minutes < 0) {
            this.hours--;
            this.minutes = this.minutes + 59;
        }
    }

    public void subtract(int minutes) {
        subtract(0, minutes);
    }

    public void subtractSpan (TimeSpan span) {
        subtract(span.getHours(), span.getMinutes());
    }

    public void scale(int factor) {

        if (factor > 0) {
            this.hours = this.minutes * factor / 60 + factor * this.hours;
            this.minutes = this.minutes * factor % 60;
        }

    }
}



