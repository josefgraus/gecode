/*
 *  Main authors:
 *     Christian Schulte <schulte@gecode.org>
 *
 *  Copyright:
 *     Christian Schulte, 2004
 *
 *  Last modified:
 *     $Date$ by $Author$
 *     $Revision$
 *
 *  This file is part of Gecode, the generic constraint
 *  development environment:
 *     http://www.gecode.org
 *
 *  See the file "LICENSE" for information on usage and
 *  redistribution of this file, and for a
 *     DISCLAIMER OF ALL WARRANTIES.
 *
 */

#include "examples/support.hh"

/** 
 * \name Graph specification for graph coloring
 *
 * The edges are described by an array of integers with even number 
 * of elements, terminated by the elements -1,-1.
 * The cliques are described by an array of integers, where the first 
 * integer gives the size of the clique, the following elements are
 * nodes for each clique. The cliques are terminated by -1 for clique size
 *
 * \relates GraphColor
 */
//@{
/// Graph specification
class GraphColorSpec {
public:
  const int  n_v; ///< Number of nodes
  const int* e;   ///< Edges
  const int* c;   ///< Cliques
};

/// First example graph: edges
static const int g1_e[] = {
  160,184,  192,199,  0,129,  20,80,  8,29,  93,171,
  101,165,  124,193,  2,100,  66,173,  151,191,  164,187,
  3,130,  118,176,  121,184,  25,106,  159,193,  121,123,
  5,62,  97,101,  6,143,  123,163,  19,125,  17,108,
  122,168,  181,184,  25,41,  62,70,  29,103,  48,67,
  46,160,  79,170,  143,152,  38,184,  2,40,  191,195,
  7,196,  62,199,  76,141,  82,166,  36,80,  51,189,
  13,97,  3,192,  90,180,  47,176,  13,172,  92,121,
  50,64,  65,113,  108,123,  26,106,  34,153,  90,123,
  34,39,  116,178,  22,179,  50,61,  84,105,  84,93,
  19,108,  29,59,  63,185,  119,129,  50,177,  80,194,
  13,36,  46,56,  38,144,  82,193,  72,93,  49,95,
  42,155,  117,140,  109,189,  19,35,  31,125,  118,191,
  163,169,  40,167,  91,127,  3,121,  124,149,  40,174,
  30,175,  19,132,  18,165,  34,93,  37,63,  10,55,
  88,95,  76,122,  7,91,  25,141,  29,173,  139,173,
  8,130,  110,158,  81,174,  113,114,  95,182,  136,149,
  5,199,  56,106,  36,120,  133,187,  111,172,  19,34,
  96,197,  32,108,  27,63,  50,188,  20,116,  50,118,
  10,50,  24,172,  86,138,  35,50,  141,153,  98,132,
  70,143,  1,97,  8,160,  37,170,  4,73,  1,94,
  88,146,  59,61,  104,156,  62,172,  117,139,  66,189,
  33,134,  122,169,  95,163,  95,152,  83,140,  110,189,
  147,159,  22,147,  59,173,  30,41,  33,183,  181,187,
  88,105,  93,151,  6,130,  24,30,  84,130,  72,120,
  118,159,  147,189,  122,149,  24,175,  39,169,  164,186,
  93,187,  13,156,  119,176,  73,91,  174,178,  71,198,
  10,134,  30,101,  79,93,  180,187,  1,50,  51,59,
  18,169,  73,153,  1,198,  137,154,  61,106,  80,113,
  48,142,  100,111,  97,133,  82,97,  136,170,  53,134,
  65,177,  7,80,  73,137,  6,70,  115,166,  72,196,
  40,109,  91,101,  2,177,  120,185,  55,65,  72,166,
  104,165,  173,187,  54,71,  3,61,  52,56,  120,149,
  64,72,  42,43,  75,185,  62,68,  108,147,  30,111,
  25,58,  39,93,  75,117,  61,194,  140,153,  80,121,
  93,102,  9,177,  7,163,  17,70,  5,168,  63,178,
  74,160,  148,158,  9,84,  30,76,  63,80,  68,99,
  20,152,  7,182,  7,22,  71,134,  32,100,  107,164,
  23,62,  5,98,  130,192,  65,144,  139,161,  24,124,
  31,47,  29,140,  61,153,  53,109,  20,26,  143,160,
  47,195,  171,172,  185,193,  128,173,  38,96,  14,171,
  176,199,  111,139,  21,54,  80,171,  116,185,  184,199,
  37,88,  62,133,  3,150,  48,109,  46,176,  24,178,
  59,172,  180,198,  64,109,  110,111,  101,146,  66,164,
  5,117,  144,179,  71,126,  166,169,  107,151,  46,85,
  106,139,  27,153,  97,148,  68,185,  17,179,  10,142,
  168,169,  4,46,  113,152,  52,176,  6,38,  22,48,
  20,120,  2,84,  71,85,  91,116,  0,189,  116,197,
  142,147,  33,165,  86,198,  146,149,  152,187,  44,62,
  48,175,  56,150,  63,161,  71,164,  17,171,  19,66,       -1,-1};
/// First example graph: cliques
static const int g1_c[] = {
  30,  6,11,14,25,40,42,48,53,61,76,80,87,89,92,108,115,120,131,132,137,145,159,162,163,164,168,172,173,176,182,
  30,  3,15,16,31,34,35,37,38,49,58,67,78,86,91,100,110,114,123,129,132,133,140,143,154,167,168,174,175,193,197,
  25,  3,10,33,38,43,45,48,51,65,66,82,88,90,93,94,103,107,128,131,141,152,155,168,185,199,
  25,  0,4,7,26,28,33,36,58,61,72,79,81,90,99,105,114,115,124,135,152,159,161,173,181,192,
  25,  12,15,28,39,43,44,45,66,83,84,85,99,102,108,112,115,120,126,131,152,157,163,171,182,183,
  25,  13,14,15,38,55,66,76,78,87,91,95,99,109,110,125,130,134,137,148,153,159,169,181,185,195,
  25,  3,4,31,35,41,42,57,60,65,66,72,74,84,86,90,91,94,96,110,139,140,141,165,179,199,
  25,  0,4,5,9,28,31,42,49,54,63,65,72,74,75,76,82,91,99,107,109,140,147,154,169,182,
  25,  4,5,10,17,41,43,48,58,65,85,92,97,107,112,114,129,131,146,150,153,158,169,176,184,191,
  25,  4,8,15,16,20,21,37,55,68,84,87,104,109,112,117,119,122,123,126,133,142,164,167,180,195,
  25,  5,6,10,11,28,30,43,46,53,60,66,79,82,105,114,116,119,124,127,147,157,171,184,195,196,
  20,  15,16,30,35,36,56,66,78,81,84,99,126,128,129,138,151,152,153,166,190,
  20,  5,21,23,29,39,40,49,69,88,114,122,127,128,142,148,155,161,171,188,190,
  20,  0,3,15,23,31,41,57,60,69,76,89,107,109,128,153,155,161,169,174,183,
  20,  9,33,43,61,64,69,85,98,100,101,114,120,138,144,172,182,184,187,188,198,
  20,  4,6,8,10,23,27,45,57,66,68,71,93,110,122,139,146,150,155,156,188,
  20,  4,14,18,22,63,77,78,83,94,98,104,114,150,166,172,177,183,186,196,199,
  20,  22,35,46,47,63,64,70,78,87,99,102,112,116,119,125,131,152,165,174,186,
  20,  1,3,13,15,19,26,46,51,65,73,76,110,114,149,152,163,166,170,178,186,
  20,  9,29,33,40,50,54,102,105,111,112,119,120,124,128,136,138,144,175,190,199,
  20,  39,75,79,102,106,112,123,125,138,145,154,155,159,162,165,168,175,181,189,196,
  20,  0,11,12,23,42,63,68,71,79,83,89,98,113,117,121,141,156,176,177,193,
  20,  10,17,31,56,77,89,102,115,116,117,118,120,136,157,163,168,172,182,193,196,
  20,  9,34,35,43,44,57,60,64,79,87,88,94,103,133,156,157,166,171,174,189,
  20,  13,21,22,31,41,45,66,67,79,86,112,116,119,146,160,171,175,181,192,195,
  20,  11,24,26,45,57,91,99,102,122,123,135,141,144,146,154,156,167,191,194,199,
  15,  17,44,53,61,82,90,95,103,107,122,124,145,169,186,190,
  15,  2,14,26,37,58,61,75,95,103,109,115,116,141,154,199,
  15,  5,13,21,28,61,64,65,73,105,115,119,132,148,154,185,
  15,  10,20,38,45,61,75,109,111,115,143,150,157,163,179,186,
  15,  9,45,48,49,51,52,57,64,70,128,158,163,182,183,192,
  15,  47,55,57,64,79,80,105,131,152,163,172,180,186,190,197,
  15,  16,36,69,84,99,113,118,121,126,137,160,162,165,177,196,
  15,  16,44,50,53,54,65,69,80,96,112,125,139,150,153,193,
  15,  6,54,72,76,86,95,96,144,145,148,151,164,168,180,183,
  15,  10,18,19,37,65,85,90,104,112,128,147,158,164,192,198,
  15,  20,21,36,50,53,74,90,96,99,124,129,140,163,171,183,
  15,  13,20,27,53,65,77,86,98,110,125,133,139,147,188,196,
  15,  23,41,43,49,58,74,77,86,111,126,150,168,173,185,189,
  15,  11,35,62,89,125,132,134,141,149,163,166,167,171,194,196,
  15,  14,28,30,52,114,115,122,125,132,135,172,177,179,181,195,
  15,  0,8,9,20,23,53,77,93,121,136,141,147,150,191,199,
  15,  3,21,47,49,91,102,106,113,124,136,140,143,177,178,194,
  15,  44,46,52,53,68,82,89,90,120,128,144,147,175,178,192,
  15,  8,16,19,21,67,72,79,82,86,90,115,116,149,152,199,
  15,  12,30,78,80,97,120,122,123,143,146,151,165,173,177,178,
  15,  9,19,39,46,91,109,128,130,131,146,148,150,178,185,198,
  10,  29,44,69,74,96,115,122,126,189,199,
  10,  22,42,52,53,97,113,146,151,160,195,
  10,  19,20,32,77,81,133,134,138,147,177,
  10,  0,4,56,59,107,109,144,149,158,167,
  10,  6,69,99,104,110,114,118,134,152,172,
  5,  25,76,126,140,143,
  5,  4,54,67,116,142,
  5,  47,52,124,151,192,
  5,  32,55,61,64,73,
  5,  11,65,128,134,190,
  5,  45,48,63,131,139,
  5,  34,55,82,108,151,
  5,  24,34,54,112,156,
  5,  12,47,72,148,163,
  5,  74,126,145,162,170,
  5,  73,78,104,175,192,
  5,  19,83,127,130,166,
  5,  20,90,98,137,165,
  5,  22,24,29,49,132,
  5,  82,92,116,134,184,
  -1};

/// First example graph
static const GraphColorSpec g1 = {
  200, g1_e, g1_c
};


/// Second example graph: edges
static const int g2_e[] = {
  63,97,  67,85,  18,180,  2,143,  55,156,  28,105,
  37,196,  26,33,  88,199,  175,179,  45,46,  62,70,
  53,58,  49,177,  91,178,  52,129,  147,165,  83,95,
  68,172,  66,150,  7,112,  71,92,  97,150,  114,116,
  56,86,  154,188,  95,97,  159,199,  68,119,  11,81,
  79,116,  64,74,  88,89,  99,114,  70,73,  87,162,
  24,119,  9,25,  174,188,  11,80,  47,198,  86,145,
  7,70,  37,170,  138,180,  66,199,  98,153,  70,142,
  84,196,  78,185,  7,131,  54,76,  69,82,  53,166,
  25,178,  3,36,  128,197,  59,96,  122,137,  54,124,
  157,162,  3,146,  72,198,  2,94,  137,158,  64,131,
  2,79,  18,119,  22,38,  92,136,  7,108,  179,194,
  68,166,  10,84,  28,192,  103,104,  28,75,  8,43,
  153,164,  59,119,  88,177,  36,70,  59,154,  57,75,
  109,174,  155,184,  16,74,  99,148,  77,121,  54,177,
  38,172,  138,174,  7,16,  28,146,  18,192,  4,154,
  17,31,  56,57,  174,177,  81,122,  101,175,  21,155,
  48,96,  124,154,  129,130,  58,169,  19,57,  115,165,
  40,117,  34,181,  28,32,  32,176,  19,119,  20,93,
  137,172,  55,135,  92,95,  34,51,  5,81,  63,118,
  72,94,  157,181,  15,68,  41,90,  35,73,  159,183,
  115,128,  28,183,  34,45,  149,177,  74,137,  51,110,
  25,170,  43,123,  53,109,  4,26,  68,80,  53,171,
  48,159,  0,28,  67,176,  87,163,  75,165,  137,162,
  150,199,  57,153,  32,93,  25,92,  13,88,  115,167,
  16,192,  113,157,  90,125,  104,188,  148,171,  96,101,
  22,68,  25,62,  89,161,  24,158,  66,190,  31,34,
  106,133,  51,102,  146,163,  31,154,  56,129,  66,157,
  38,93,  73,166,  117,174,  93,161,  3,95,  86,181,
  131,139,  5,182,  30,66,  0,11,  88,107,  54,101,
  36,66,  25,176,  8,38,  31,177,  78,195,  122,179,
  42,60,  83,112,  149,161,  184,188,  65,126,  74,198,
  38,80,  135,172,  43,156,  148,151,  135,195,  111,184,
  10,14,  97,152,       -1,-1};
/// Second example graph: cliques
static const int g2_c[] = {
  30,  10,11,17,20,24,29,33,40,45,50,51,76,77,85,88,101,114,120,122,127,129,136,144,147,148,157,169,180,184,193,
  30,  0,2,14,21,38,40,44,51,72,82,91,99,106,109,119,123,126,136,141,154,157,161,163,165,166,171,175,182,183,196,
  30,  2,17,20,30,35,36,37,39,46,56,61,72,75,77,80,84,85,96,97,100,107,112,123,156,160,163,175,181,182,195,
  25,  11,19,36,41,44,59,60,73,74,89,93,94,108,109,113,130,132,153,163,167,182,186,193,196,199,
  25,  2,11,25,30,31,41,49,51,52,53,85,86,93,101,105,108,111,130,135,144,150,183,185,191,194,
  25,  1,6,9,11,12,13,19,21,33,49,51,77,124,128,130,131,140,146,147,161,171,180,181,185,198,
  25,  3,5,31,39,42,57,59,61,90,93,98,102,106,121,129,132,140,160,165,166,168,185,187,193,194,
  25,  9,12,16,23,33,41,44,61,68,73,85,93,96,113,118,122,125,127,129,133,139,146,181,186,199,
  25,  6,23,35,42,45,57,65,67,70,77,80,96,100,105,114,119,129,145,146,152,157,160,166,190,195,
  25,  8,18,19,27,36,40,49,52,60,65,75,84,85,96,97,107,109,110,120,122,132,154,155,172,189,
  25,  1,25,27,37,39,45,56,61,69,70,80,87,89,102,111,115,120,126,134,146,156,169,173,175,192,
  20,  8,14,20,21,32,39,50,55,88,91,102,120,126,142,159,165,171,175,184,186,
  20,  10,15,35,43,50,52,60,77,80,81,85,87,106,120,145,151,155,159,176,196,
  20,  10,17,20,33,46,55,60,68,95,96,103,112,117,118,120,123,127,141,147,179,
  20,  9,34,41,52,56,72,73,100,102,116,124,131,138,155,157,158,172,173,182,183,
  20,  0,14,16,27,29,44,70,95,101,104,115,127,140,158,161,168,170,173,181,189,
  20,  6,14,17,18,23,27,50,51,83,84,93,107,108,116,122,136,154,159,172,185,
  20,  11,16,17,21,32,38,45,49,55,56,84,88,102,123,126,133,173,189,195,198,
  20,  0,14,21,29,30,40,63,67,93,98,116,122,131,140,150,152,174,178,183,190,
  20,  8,14,28,36,44,65,72,79,84,111,114,124,130,134,140,158,182,185,193,197,
  20,  9,10,12,17,28,42,46,50,57,62,90,117,132,149,168,176,178,182,187,188,
  20,  2,4,22,27,31,32,65,74,108,117,132,142,153,159,160,178,180,187,192,195,
  20,  2,4,7,21,56,64,67,100,103,130,135,140,147,151,156,161,167,191,193,196,
  20,  6,18,24,30,50,51,67,82,84,88,93,95,106,113,138,146,168,187,190,198,
  20,  28,37,44,98,99,107,112,119,129,132,135,151,156,167,168,179,182,190,198,199,
  15,  4,37,61,64,67,77,93,103,105,118,136,159,169,177,193,
  15,  17,44,53,61,82,90,95,103,107,122,124,145,169,186,190,
  15,  21,54,80,100,110,120,126,127,132,142,149,150,162,181,186,
  15,  3,7,21,22,40,41,82,94,96,98,126,140,143,147,152,
  15,  4,14,58,66,80,100,107,111,126,133,140,141,148,155,167,
  15,  31,38,44,48,59,74,75,77,100,105,139,168,171,182,187,
  15,  0,5,55,62,66,67,74,84,92,128,160,163,188,189,195,
  15,  0,36,55,73,80,96,121,133,167,173,190,191,193,195,198,
  15,  21,33,41,43,52,62,69,77,88,110,114,118,139,142,187,
  15,  12,14,23,29,44,58,67,74,124,149,150,156,167,171,183,
  15,  22,33,36,48,60,63,90,92,107,108,137,140,144,165,193,
  15,  11,24,40,45,49,59,72,123,125,132,151,161,167,179,184,
  15,  4,19,20,48,61,76,98,106,136,147,155,177,183,191,192,
  15,  17,22,28,35,55,74,86,90,98,106,121,138,168,190,195,
  15,  24,30,35,44,55,63,80,120,128,130,148,160,163,166,192,
  15,  20,30,59,64,69,94,104,106,139,140,144,147,156,161,199,
  15,  13,30,38,49,54,61,86,95,103,105,131,148,156,162,180,
  15,  2,25,34,41,46,63,69,81,91,113,139,159,186,188,190,
  15,  1,6,14,35,47,50,66,81,90,136,137,152,156,168,195,
  15,  34,37,47,52,94,100,104,105,107,131,147,171,186,191,192,
  15,  9,14,29,37,109,125,137,142,145,147,151,159,167,178,192,
  15,  13,45,60,62,78,99,104,118,142,143,156,179,189,191,197,
  15,  3,15,23,33,66,71,82,89,99,110,113,135,143,158,171,
  15,  27,39,101,102,118,133,134,138,141,144,145,148,165,169,189,
  15,  12,18,20,36,50,51,53,76,86,120,141,176,178,186,198,
  10,  6,8,17,77,109,112,115,124,129,193,
  10,  21,31,51,58,86,112,117,126,127,143,
  10,  10,74,87,108,123,134,157,180,186,190,
  10,  13,14,15,44,67,118,133,142,146,193,
  10,  40,44,46,66,73,128,141,161,174,192,
  5,  25,117,163,165,192,
  5,  40,46,105,121,134,
  5,  3,12,56,90,126,
  5,  13,95,98,120,188,
  5,  3,98,111,128,194,
  5,  4,21,51,65,73,
  5,  36,106,124,132,197,
  5,  5,35,57,91,144,
  5,  0,19,122,177,190,
  5,  85,98,111,113,134,
  5,  49,85,107,139,149,
  5,  54,88,102,111,172,
  5,  41,74,115,170,184,
  5,  33,70,123,151,159,
  5,  50,82,117,123,163,
  -1};

/// Second example graph
static const GraphColorSpec g2 = {
  200, g2_e, g2_c
};
//@}

/**
 * \brief %Example: Clique-based graph coloring
 *
 * \ingroup Example
 *
 */
class GraphColor : public Example {
private:
  const GraphColorSpec& g;
  /// Color of nodes
  IntVarArray v;
  /// Number of colors
  IntVar m;
public:
  /// The actual model
  GraphColor(const Options& opt)
    : g(opt.size == 1 ? g2 : g1), 
      v(this,g.n_v,0,g.n_v), 
      m(this,0,g.n_v) {
    for (int i = g.n_v; i--; )
      rel(this, v[i], IRT_LQ, m);
    for (int i = 0; g.e[i] != -1; i += 2)
      rel(this, v[g.e[i]], IRT_NQ, v[g.e[i+1]]);

    const int* c = g.c;
    for (int i = *c++; i--; c++)
      rel(this, v[*c], IRT_EQ, i);
    while (*c != -1) {
      IntVarArgs x(*c); c++;
      for (int i = x.size(); i--; c++)
	x[i] = v[*c];
      distinct(this, x, opt.icl);
    }
    IntVarArgs ma(1);
    ma[0] = m;
    branch(this, ma, BVAR_NONE, BVAL_MIN);
    if (opt.naive) {
      branch(this, v, BVAR_SIZE_MIN, BVAL_MIN);
    } else {
      branch(this, v, BVAR_DEGREE_MAX, BVAL_MIN);
    }
  }
  /// Constructor for cloning \a s
  GraphColor(bool share, GraphColor& s) : Example(share,s), g(s.g) {
    v.update(this, share, s.v);
    m.update(this, share, s.m);
  }
  /// Copying during cloning
  virtual Space*
  copy(bool share) {
    return new GraphColor(share,*this);
  }
  /// Print the solution
  virtual void
  print(void) {
    std::cout << "\tm = " << m << std::endl
	      << "\tv[] = {";
    for (int i = 0; i < v.size(); i++) {
      std::cout << v[i] << ", ";
      if ((i+1) % 15 == 0)
	std::cout << std::endl << "\t       ";
    }
    std::cout << "};" << std::endl;
  }
};


/** \brief Main-function
 *  \relates GraphColor
 */
int
main(int argc, char** argv) {
  Options opt("GraphColor");
  opt.naive      = false;
  opt.icl        = ICL_DOM;
  opt.iterations = 5;
  opt.c_d        = 10;
  opt.parse(argc,argv);
  Example::run<GraphColor,DFS>(opt);
  return 0;
}

// STATISTICS: example-any
