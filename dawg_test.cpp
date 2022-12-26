#include "dawg.h"

int main() {
    // completeWord("te");
    insertWord("test");
    insertWord("toast");
    insertWord("fruits");
    auto d = getRoot();
    printNode(d);
    printNode(d->children['t' - 'a'].get());
    printNode(d->children['t' - 'a']->children['o' - 'a'].get());
    printNode(d->children['t' - 'a']->children['e' - 'a'].get());

}