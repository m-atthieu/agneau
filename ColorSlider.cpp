#include "ColorSlider.hpp"

namespace Agneau {
  ColorSlider::ColorSlider(const QString label) : QWidget()
  {
    this->label = new QLabel(label);
    this->spinBox = new QSpinBox;
    this->slider = new QSlider(Qt::Vertical);
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(this->slider);
    layout->addWidget(this->label);
    layout->addWidget(this->spinBox);
    this->setLayout(layout);

    /* internal widget connection */
    QObject::connect(this->spinBox, SIGNAL(valueChanged(int)), 
                     this, SLOT(setValue(int)));
    QObject::connect(this->slider, SIGNAL(valueChanged(int)), 
                     this, SLOT(setValue(int)));
  }

  void ColorSlider::setValue(int value)
  {
      this->value = value;
      this->spinBox->setValue(value);
      this->slider->setValue(value);
      emit(valueChanged(value));
  }
  
  void ColorSlider::setMaximum(int maximum)
  {
    this->slider->setMaximum(maximum);
  }
};
