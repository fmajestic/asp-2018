atom * dohvatiIti(atom * glava, int i) {
    int x;
    for (x = 1; x++ < i && glava; glava = glava->sljed);
    return glava;
}
