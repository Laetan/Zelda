// zelda.h rajouter:
public:
    void blink();
protected:
    int blinkCounter = 0;
    int blinkOn = 0;

// zelda.cpp rajouter:
//Dans update():
if(blinkOn != 0)
	blink();
		
// Dans checkCollideWithElement():
else if(element->getName()=="pewpew"){
			((GameScene*) this->scene())->remove(element);
			qDebug()<<"OUCH!";
			//takeDmg();
			blinkOn = 3;
        }
		
void Zelda::blink()
{
    if(blinkCounter==0){
		setVisible(!isVisible());
		blinkCounter=1;
    }
    else    blinkCounter--;
    blinkOn--;
}