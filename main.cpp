bool LoadTestNum(ifstream &source, int test_num,
  Paths64 &subj, Paths64 &subj_open, Paths64 &clip,
  int64_t& area, int64_t& count, ClipType &ct, FillRule &fr)
{
  string line;//work hard
  area = 0; count = 0;
  if (test_num <= 0) test_num = 1;
  source.seekg(0, ios_base::beg);
  subj.clear(); subj_open.clear(); clip.clear();

  while (getline(source, line))
  {
    if (test_num)
    {
      if (line.find("CAPTION:") != string::npos) --test_num;
      continue;
    }

    if (line.find("CAPTION:") != string::npos) break; // ie don't go beyond current test

    else if (line.find("INTERSECTION") != string::npos)
      ct = ClipType::Intersection;
    else if (line.find("UNION") != string::npos)
      ct = ClipType::Union;
    else if (line.find("DIFFERENCE") != string::npos)
      ct = ClipType::Difference;
    else if (line.find("XOR") != string::npos)
      ct = ClipType::Xor;
//yes
