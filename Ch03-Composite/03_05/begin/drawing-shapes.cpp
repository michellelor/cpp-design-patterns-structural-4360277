#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Abstract base class for concrete Shape classes
class Shape
{
public:
    virtual void draw() const = 0;
    virtual string getName() const = 0;
    virtual ~Shape() = default;
};

// Concrete Shape classes
class Circle : public Shape
{
public:
    explicit Circle(double radius) : m_Radius(radius) {}

    void draw() const override
    {
        cout << "Drawing a circle with radius " << m_Radius << endl;
    }

    string getName() const override
    {
        return "Circle";
    }

private:
    double m_Radius;
};

class Rectangle : public Shape
{
public:
    Rectangle(double width, double height) : m_Width(width), m_Height(height) {}

    void draw() const override
    {
        cout << "Drawing a rectangle with width " << m_Width << " and height " << m_Height << endl;
    }

    string getName() const override
    {
        return "Rectangle";
    }

private:
    double m_Width;
    double m_Height;
};

class Triangle : public Shape
{
public:
    Triangle(double side1, double side2, double side3) : m_Side1(side1), m_Side2(side2), m_Side3(side3) {}

    void draw() const override
    {
        cout << "Drawing a triangle with sides " << m_Side1 << ", " << m_Side2 << ", and " << m_Side3 << endl;
    }

    string getName() const override
    {
        return "Triangle";
    }

private:
    double m_Side1;
    double m_Side2;
    double m_Side3;
};

class CompositeShape : public Shape
{
private:
    vector<Shape *> m_Shapes;

public:
    // Add circle shape
    void addShape(Shape &shape)
    {
        cout << "Adding shape..." << endl;
        m_Shapes.push_back(&shape);
    }

    void removeShape(Shape &shape)
    {
        cout << "Removing shape..." << endl;
        Shape *shape_Ptr = &shape;
        auto it = std::find(m_Shapes.begin(), m_Shapes.end(), shape_Ptr);
        if (it != m_Shapes.end())
            m_Shapes.erase(it);
    }

    void draw() const override
    {
        for (const Shape *s : m_Shapes)
        {
            s->draw();
        }
    }

    string getName() const override
    {
        return "Shape Container";
    }
};

int main()
{
    Circle c(5);
    Rectangle r(10, 20);
    Triangle t(3, 4, 5);

    CompositeShape cs;

    cs.addShape(c);
    cs.addShape(r);
    cs.addShape(t);

    cs.draw();

    cs.removeShape(r);

    cs.draw();

    return 0;
}
