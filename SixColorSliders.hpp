#ifndef __SIXCOLORSLIDERS_HPP__
#define __SIXCOLORSLIDERS_HPP__

#include <QtGui>

#include "ColorSlider.hpp"

namespace Agneau {
  class SixColorSliders: public QWidget
  {
    Q_OBJECT

    public:
    SixColorSliders();
    void setMaximum(int maximum);

  signals:
    void channelChanged(QString channel, int value);

  private slots:
    void redChannelChanged(int value);
    void greenChannelChanged(int value);
    void blueChannelChanged(int value);
    void magentaChannelChanged(int value);
    void yellowChannelChanged(int value);
    void cyanChannelChanged(int value);

  private:
    ColorSlider* rColorSlider;
    ColorSlider* gColorSlider;
    ColorSlider* bColorSlider;
    /* magenta */
    ColorSlider* mColorSlider;
    /* yellow */
    ColorSlider* yColorSlider;
    /* cyan */
    ColorSlider* cColorSlider;
  };
};

#endif /* __SIXCOLORSLIDERS_HPP__ */
