# OOP and C++ principles

## Inheritance
Inheritance It is a mechanism where you can to derive a class from another class for a hierarchy of classes that share a set of attributes and methods.

### Public Inheritance:
In the code `Satellite` inherits from `SpaceObject` with a `public` inheritance therefor it's attributes and methods will be present in the child class as well. It makes public members of the base class `public` in the derived class, and the `protected` members of the base class remain `protected` in the derived class.

```bash
class Satellite : public SpaceObject {
   private:
    double x, y, z;
    Orbit orbit;
```

## Composition
It is a special type of association between classes that represents a stronger relationship than a regular association. In a composition relationship, one class is the owner of the other class and is responsible for its creation and destruction.

In the code `Satellite` has a relationship with `Orbit` as “has-a” relationship.

```bash
class Satellite : public SpaceObject {
   private:
    double x, y, z;
    Orbit orbit;
```

## Encapsulation
It is to make sure that "sensitive" data is hidden from users. To achieve this, you must declare class variables/attributes as private (cannot be accessed from outside the class). If you want others to read or modify the value of a private member, you can provide public get and set methods.

For example, `Orbit` has somee private attributes that can only be accesed by public get methods.

```bash
class Orbit {
   private:
    double semi_major_axis;
    double eccentricity;
```

```bash
   public:
    auto get_semi_major_axis() const -> double { return semi_major_axis; }
    auto get_eccentricity() const -> double { return eccentricity; }
```

## C++ Access Specifiers

`public` - members are accessible from outside the class
`private` - members cannot be accessed (or viewed) from outside the class
`protected` - members cannot be accessed from outside the class, however, they can be accessed in inherited classes.

In the code we have some examples where `Orbit` attributes are private and can only accesed by public get functions. While `Satellite` inherits protected attributes from his father class `SpaceObject`.

```bash
class SpaceObject {
   protected:
    std::string name;
```

```bash
class Orbit {
   private:
    double semi_major_axis;
    double eccentricity;
```

```bash
class Satellite : public SpaceObject {
   private:
    double x, y, z;
    Orbit orbit;
```
