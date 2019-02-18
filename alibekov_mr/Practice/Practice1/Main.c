#include<stdio.h>

void main()
{
  double pl_DVP, pl_DSP, pl_d, m, m_stenka, m_2bokovini, m_2krishi, m_2dveri, m_polki;
  double w, h, d;
  printf("Vvedite (v sm): w (ot 80 do 120), h (ot 180 do 220), d (ot 50 do 90)\n");
  scanf("%lf %lf %lf", &w, &h, &d);
  printf("Vvedite (v kg/(m^3)): pl_DVP, pl_DSP, pl_d\n");
  scanf("%lf %lf %lf", &pl_DVP, &pl_DSP, &pl_d);
  if ((w < 80) || (w > 120) || (h < 180) || (h > 220) || (d < 50) || (d > 90) || (pl_DVP <= 0) || (pl_DSP <= 0) || (pl_d <= 0))
  {
    printf("Vvedeni nepravilnie parametri\n");
    return;
  }
  w *= 0.01;
  h *= 0.01;
  d *= 0.01;
  m_stenka = (h * w * 0.005) * pl_DVP;
  m_2bokovini = 2 * (h * d * 0.015) * pl_DSP;
  m_2krishi = 2 * (w * d * 0.015) * pl_DSP;
  m_2dveri = 2 * (h * (w / 2) * 0.01) * pl_d;
  m_polki = ((int)((h - 2 * 0.015) / (0.4 + 0.015)) * (w - 2 * 0.015) * (d - 0.005) * 0.015) * pl_DSP;
  m = m_stenka + m_2bokovini + m_2krishi + m_polki + m_2dveri;
  printf("%lf kg\n", m);
}