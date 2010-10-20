#include "RGBColorSliders.hpp"

namespace Agneau {
  RGBColorSliders::RGBColorSliders(): QWidget()
  {
    this->rColorSlider = new ColorSlider("red");
    this->gColorSlider = new ColorSlider("green");
    this->bColorSlider = new ColorSlider("blue");
    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(this->rColorSlider);
    layout->addWidget(this->gColorSlider);
    layout->addWidget(this->bColorSlider);
    this->setLayout(layout);

    /* mise en place des signaux */
    /* on renvoit le nom du canal changé avec la nouvelle valeur */
    QObject::connect(this->rColorSlider, SIGNAL(valueChanged(int)), 
                     this, SLOT(redChannelChanged(int)));
    QObject::connect(this->gColorSlider, SIGNAL(valueChanged(int)), 
                     this, SLOT(greenChannelChanged(int)));
    QObject::connect(this->bColorSlider, SIGNAL(valueChanged(int)), 
                     this, SLOT(blueChannelChanged(int)));
  }

  void RGBColorSliders::redChannelChanged(int value)
  {
      emit channelChanged(QString("red"), value);
  }

  void RGBColorSliders::greenChannelChanged(int value)
  {
      emit channelChanged(QString("green"), value);
  }

  void RGBColorSliders::blueChannelChanged(int value)
  {
      emit channelChanged(QString("blue"), value);
  }

  void RGBColorSliders::setMaximum(int maximum)
  {
    this->rColorSlider->setMaximum(maximum);
    this->gColorSlider->setMaximum(maximum);
    this->bColorSlider->setMaximum(maximum);
  }
};
