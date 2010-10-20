#ifndef __RGBCOLORSLIDERS_HPP__
#define __RGBCOLORSLIDERS_HPP__

#include <QtGui>

#include "ColorSlider.hpp"

namespace Agneau {
  class RGBColorSliders: public QWidget
  {
    Q_OBJECT
    
    public:
    RGBColorSliders();
    void setMaximum(int maximum);

  signals:
    void channelChanged(QString channel, int value);
                                                   
  private slots:
    void redChannelChanged(int value);
    void greenChannelChanged(int value);
    void blueChannelChanged(int value);

  private:
    /* red */
    ColorSlider* rColorSlider;
    /* green */
    ColorSlider* gColorSlider;
    /* blue */
    ColorSlider* bColorSlider;
  };
};

#endif /* __RGBCOLORSLIDERS_HPP__ */
