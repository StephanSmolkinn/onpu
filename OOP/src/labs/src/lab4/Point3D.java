package labs.src.lab4;

import java.awt.*;

public class Point3D extends Point {
    private int z;
    public Point3D() {
        x = 0;
        y = 0;
        z = 0;
    }

    public int getZ() {
        return z;
    }

    public void setZ(int z) {
        this.z = z;
    }

    public Point3D(int x, int y, int z) {
        setLocation(x, y, z);
    }

    public void setLocation(int x, int y, int z) {
        setLocation(x, y);
        this.z = z;
    }

    @Override
    public void setLocation(int x, int y) {
        this.x = x;
        this.y = y;
        this.z = 0;
    }

    public double distance(Point3D i) {
        int d1 = x - i.x;
        int d2 = y - i.y;
        int d3 = z - i.z;
        return Math.sqrt((double) ((d1 ^ 2 + d2 ^ 2 + d3 ^ 2)));
    }

    @Override
    public String toString() {
        return "(" + x + ";" + y + ";" + z + ")";
    }

    public double distanceFromOrigin() {
        return Math.sqrt((double) (x * x + y * y + z * z));
    }
}
