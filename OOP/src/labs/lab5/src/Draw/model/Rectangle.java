package labs.lab5.src.Draw.model;

import java.awt.*;
import java.awt.geom.Rectangle2D;

abstract class Rectangle extends DrawShape {

    public Rectangle() {
    }

    public Rectangle(Point startPoint, Point endPoint) {
        super(startPoint, endPoint);
    }

    // Для відтворення прямокутника ми використовуємо клас Rectangle2D.Double (клас Double усередині класу Rectangle2D).
    // Клас Rectangle2D.Double приймає координати типу Double
    @Override
    public Shape getShape(Point startPoint, Point endPoint) {
        return new Rectangle2D.Double(Math.min(startPoint.getX(), endPoint.getX()), Math.min(startPoint.getY(), endPoint.getY()),
                Math.abs(startPoint.getX() - endPoint.getX()), Math.abs(startPoint.getY() - endPoint.getY()));
    }

}
