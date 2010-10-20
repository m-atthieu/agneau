#ifndef __COLORSLIDERS_HPP__
#define __COLORSLIDERS_HPP__

#include <QtGui>

namespace Agneau {
  /**
   *
   */
  class ColorSlider: public QWidget
  {
    Q_OBJECT
    
    public:
    ColorSlider(const QString label);
    void setMaximum(int maximum);
                                
  public slots:
    void setValue(int value);
    
  signals:
    void valueChanged(int value);
    
  private:
    QSlider* slider;
    QSpinBox* spinBox;
    QLabel* label;
    int minimum;
    int max;
    int value;
  };
};

#endif /* __COLORSLIDERS_HPP__ */
