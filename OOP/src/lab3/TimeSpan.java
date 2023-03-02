package lab3;

public class TimeSpan {
    private int hours;
    private int minutes;

    public TimeSpan(int hours, int minutes) {
        this.hours = hours;
        this.minutes = minutes;
    }

    public int getHours() {

        if (hours < 0)
            return 0;

        return hours;

    }

    public int getMinutes() {

        if (minutes < 0)
            return 0;

        if (minutes >= 60) {
            hours++;
            minutes = 0;
        }

        return minutes;

    }

    public void add(int hours, int minutes) {

        if (hours < 0)
            hours = 0;

        if (minutes < 0)
            minutes = 0;

        if (minutes < 60) {
            this.hours = this.hours + hours;
            this.minutes = this.minutes + minutes;
        }
        if (this.minutes >= 60)
            this.hours++;

        if (this.minutes >= 60)
            this.minutes = this.minutes - 60;

    }

    private void addTimeSpan(TimeSpan timespan) {

        if (hours < 0)
            hours = 0;

        if (minutes < 0)
            minutes = 0;

        if (minutes < 60) {
            hours = hours + timespan.hours;
            minutes = minutes + timespan.minutes;
        }

        if (minutes >= 60)
            hours++;

        if (minutes >= 60)
            minutes = minutes - 60;

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

    public void subtract(TimeSpan span) {

        if (span.hours >= this.hours && span.minutes > minutes) {
            span.hours = 0;
            span.minutes = 0;
        }
        if (span.hours > hours)
            span.hours = 0;

        if (span.minutes < 60) {
            hours = hours - span.hours;
            if (span.minutes > minutes)
                hours--;
            minutes = minutes - span.minutes;
            if (minutes < 0)
                minutes = 60 + (minutes);
        }
        if (minutes < 0)
            hours--;

    }

    public void scale(int factor) {

        if (factor > 0) {
            this.hours = this.minutes * factor / 60 + factor * this.hours;
            this.minutes = this.minutes * factor % 60;
        }

    }
}
