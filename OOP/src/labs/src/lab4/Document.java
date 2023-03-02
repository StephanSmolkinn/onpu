package labs.src.lab4;

import javax.print.Doc;
import java.util.Date;

public class Document {
    private String[] authors;
    private Date date;

    public String[] getAuthors() {
    }

    public void addAuthor(String name) {
    }

    public Date getDate() {
    }
}

class EMail extends Document {
    private String subject;
    private String[] to;

    public String getSubject() {
    }

    public String[] getTo() {
    }
}

class Book extends Document {
    private String litle;

    public String getLitle() {
    }
}

