package lab4;

class Piston {
}
class Crankshaft {
}

class Engine {
    private Piston[] piston;
    private Crankshaft crankshaft;

    public Engine() {
        piston = new Piston[8];
        crankshaft = new Crankshaft();
    }
}

class Boat {
    private Engine engine;
    private Propeller[] propeller;

    public Boat() {
        propeller = new Propeller[4];
        engine = new Engine();
    }
}
class Propeller {
}

class Wheel {
}

class Car {
    private Engine engine;
    private Wheel[] wheel;

    public Car() {
        wheel = new Wheel[4];
        engine = new Engine();
    }
}
