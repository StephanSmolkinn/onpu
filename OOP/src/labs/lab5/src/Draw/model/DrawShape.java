package labs.lab5.src.Draw.model;

import java.awt.*;

/*
 * Клас "Фігура для малювання".
 * Клас містить початкову та кінцеву точку, а також різні методи
 */
public abstract class DrawShape {

    public static DrawShape newInstance(int shapeType) {
        DrawShape shape = null;
        if (shapeType == DrawShape.SHAPE_RECTANGLE) {
            shape = new Rectangle() { };
        } else if (shapeType == DrawShape.SHAPE_ROUNDED_RECT) {
            shape = new RoundedRectangle() { };
        } else if (shapeType == DrawShape.SHAPE_ELLIPSE) {
            shape = new Ellipse() { };
        }
        return shape;
    }

    // Константы для типів фигур
    public static final int SHAPE_RECTANGLE = 0;
    public static final int SHAPE_ROUNDED_RECT = 1;
    public static final int SHAPE_ELLIPSE = 2;

    // Початкова та кінцева точки
    private Point startPoint;
    private Point endPoint;

    // Конструктор без пареметрів.
    public DrawShape() {
        this(new Point(0, 0), new Point(0, 0));
    }

    // Конструктор з початковими координатами
    public DrawShape(Point startPoint, Point endPoint) {
        this.startPoint = startPoint;
        this.endPoint = endPoint;
    }

    // Метод повертає фігуру, яку можна намалювати
    public Shape getShape() {
        return this.getShape(startPoint, endPoint);
    }

    // Так, як ми не можемо намалювати просто "фігуру", то метод повертає null
    public Shape getShape(Point startPoint, Point endPoint) {
        return null;
    }

    public void setStartPoint(Point startPoint) {
        this.startPoint = startPoint;
    }

    public void setEndPoint(Point endPoint) {
        this.endPoint = endPoint;
    }
}
