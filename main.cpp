#include <SFML/Graphics.hpp>

using namespace sf;

void sun(RenderWindow & window)
{
    CircleShape shape(100.f); // создаём объект круг и устанавливаем радиус
    shape.setPosition(150, 450);           // устанавливаем начальную позицию
    RectangleShape rect(Vector2f(1500, 450));
    rect.setPosition(0, 450);
    int CircleColor = 0, CircleColor1 = 0, RectColor = 0, Period = 0;
    double rad = 100;
    bool v = true, t = true;

    while (true) 
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) window.close();
        }
        if (Period != 255 && v) {
            rad -= 0.2f;
            shape.move(2, -1.8); Period++; RectColor++;
            if (CircleColor <= 252) CircleColor += 2; else if (CircleColor1 <= 252) CircleColor1 += 2;
        }
        else { rad += 0.2f; shape.move(2, 1.8); Period--; RectColor--; v = false; if (CircleColor1 > 2) CircleColor1 -= 2; else if (CircleColor > 2) CircleColor -= 2; }
        if (Period < 0) {
            return;
        }
        shape.setRadius(rad);
        shape.setFillColor(Color(255, CircleColor, CircleColor1)); // закрашиваем наш круг
        rect.setFillColor(Color(0, RectColor, 0));
        window.clear(Color(0, CircleColor1, CircleColor));
        window.draw(shape);
        window.draw(rect);
        window.display();
    }
}

void moon(RenderWindow& window)
{
    CircleShape shape(100.f);              // создаём объект круг и устанавливаем радиус
    shape.setPosition(150, 450);           // устанавливаем начальную позицию
    
    RectangleShape rect(Vector2f(1500, 450));
    rect.setPosition(0, 450);
    rect.setFillColor(Color(0, 0, 0));
   
    VertexArray stars(Points,50);
    int delaystars = 0;
    int Period = 0,i=0;
    double rad = 60;
    bool v = true, t = true;

    while (true)
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) window.close();
        }
        if (Period != 255 && v) {
            rad -= 0.1f;
            shape.move(2, -1.8); Period++;
        }
        else { rad += 0.1f; shape.move(2, 1.8); Period--;  v = false; }
        if (Period < 0) {
            return;
        }
        if (delaystars<20) delaystars++;
        if (i < 49 && delaystars>4) {  stars[i].color = Color(255, 255, 255);
        stars[i].position = Vector2f(rand() % 1500, rand() % 450); i++; delaystars = 0;
        }

        shape.setRadius(rad);
                
        window.clear();
        window.draw(stars);
        window.draw(shape);
        window.draw(rect);
        window.display();
    }

}

int main()
{
    srand(time(0));
    ContextSettings settings;
    settings.antialiasingLevel = 16; // сглаживание краёв фигур
    RenderWindow window(VideoMode(1500, 900), L"Новый проект", Style::Default, settings);
    window.setFramerateLimit(40); // частота кадров    
   
        
    while (window.isOpen())
    {
       sun(window);
       moon(window);

    }
    return 0;
}