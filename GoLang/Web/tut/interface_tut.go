package main

import(
	"fmt"
)

var pi = float64(22.0/7)

type twoDimFigure interface{
	attributes()
	area() float64
	perimeter() float64
}

type circle struct{
	radius float64
}

type rectangle struct{
	length,breadth float64
}

type triangle struct{
	a,b,c,base,height float64
}

func(c circle)area()float64{
	return pi*c.radius*c.radius
}

func (c circle)perimeter()float64{
	return 2*pi*c.radius
}

func (c circle)attributes(){
	fmt.Println("raduis = ",c.radius)
}

func(r rectangle)area()float64{
	return r.length*r.breadth
}

func (r rectangle)perimeter()float64{
	return 2*(r.length+r.breadth)
}

func (r rectangle)attributes(){
	fmt.Println("length = ",r.length," ; breadth = ",r.breadth)
}

func(t triangle)area()float64{
	return 0.5*t.base*t.height
}

func (t triangle)perimeter()float64{
	return t.a+t.b+t.c
}

func (t triangle)attributes(){
	fmt.Println("a = ",t.a," ; b = ",t.b," ; c = ",t.c," ; base = ",t.base," ; height = ",t.height)
}

func measure(myTwoDimFigure twoDimFigure){
	myTwoDimFigure.attributes()
	fmt.Println("area = ",myTwoDimFigure.area())
	fmt.Println("perimeter = ",myTwoDimFigure.perimeter())
}

func main(){
	myRect := rectangle{length:2,breadth:4}
	myCircle := circle{radius:5}
	myTriangle := triangle{a:2,b:2,c:2,base:2,height:2.1}

	fmt.Println("rectangle :: ")
	measure(myRect)
	fmt.Println("circle :: ")
	measure(myCircle)
	fmt.Println("triangle :: ")
	measure(myTriangle)
	
}