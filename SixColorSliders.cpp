#include "SixColorSliders.hpp"

namespace Agneau {
  SixColorSliders::SixColorSliders() : QWidget()
  {
      this->rColorSlider = new ColorSlider("red");
      this->gColorSlider = new ColorSlider("green");
      this->bColorSlider = new ColorSlider("blue");
      QHBoxLayout* layout1 = new QHBoxLayout;
      layout1->addWidget(this->rColorSlider);
      layout1->addWidget(this->gColorSlider);
      layout1->addWidget(this->bColorSlider);
      this->cColorSlider = new ColorSlider("cyan");
      this->mColorSlider = new ColorSlider("magenta");
      this->yColorSlider = new ColorSlider("yellow");
      QHBoxLayout* layout2 = new QHBoxLayout;
      layout2->addWidget(this->cColorSlider);
      layout2->addWidget(this->mColorSlider);
      layout2->addWidget(this->yColorSlider);
      QVBoxLayout* layout = new QVBoxLayout;
      layout->addLayout(layout1);
      layout->addLayout(layout2);
      this->setLayout(layout);

      /**/
      QObject::connect(this->rColorSlider, SIGNAL(valueChanged(int)), 
                       this, SLOT(redChannelChanged(int)));
      QObject::connect(this->gColorSlider, SIGNAL(valueChanged(int)), 
                       this, SLOT(greenChannelChanged(int)));
      QObject::connect(this->bColorSlider, SIGNAL(valueChanged(int)), 
                       this, SLOT(blueChannelChanged(int)));
      QObject::connect(this->mColorSlider, SIGNAL(valueChanged(int)), 
                       this, SLOT(magentaChannelChanged(int)));
      QObject::connect(this->yColorSlider, SIGNAL(valueChanged(int)), 
                       this, SLOT(yellowChannelChanged(int)));
      QObject::connect(this->cColorSlider, SIGNAL(valueChanged(int)), 
                       this, SLOT(cyanChannelChanged(int)));
  }
  
  void SixColorSliders::redChannelChanged(int value)
  {
      emit channelChanged(QString("red"), value);
  }

  void SixColorSliders::greenChannelChanged(int value)
  {
      emit channelChanged(QString("green"), value);
  }

  void SixColorSliders::blueChannelChanged(int value)
  {
      emit channelChanged(QString("blue"), value);
  }
  void SixColorSliders::magentaChannelChanged(int value)
  {
      emit channelChanged(QString("magenta"), value);
  }

  void SixColorSliders::yellowChannelChanged(int value)
  {
      emit channelChanged(QString("yellow"), value);
  }

  void SixColorSliders::cyanChannelChanged(int value)
  {
      emit channelChanged(QString("cyan"), value);
  }

  void SixColorSliders::setMaximum(int maximum)
  {
    this->rColorSlider->setMaximum(maximum);
    this->gColorSlider->setMaximum(maximum);
    this->bColorSlider->setMaximum(maximum);
    this->cColorSlider->setMaximum(maximum);
    this->mColorSlider->setMaximum(maximum);
    this->yColorSlider->setMaximum(maximum);
  }
};
