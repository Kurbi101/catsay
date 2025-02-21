#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_POEMS 53 /* total number of poems */

char* heine_db[] = {
    "Think of Germany in the night,\n"
    "    Then am I torn from sleep outright.\n",

    "The rose, the lily, the dove, the sun,\n"
    "    I once loved them all in rapture as one.\n"
    "I love them no more, I love alone\n"
    "    The One, the Small, the Pure, my Own.\n",

    "Softly rings through heart and mind\n"
    "    Spring's sweet bell in gentle chime.\n"
    "Little song of spring, now sing,\n"
    "    Sing into the distant time.\n",

    "A new song, a better song,\n"
    "    O friends, I wish to write!\n",

    "And if you do not stake your life,\n"
    "    Life will never be won.\n",

    "Where books are burned,\n"
    "    In the end people will burn too.\n",

    "The time is a blooming rose,\n"
    "    But its petals fall so light.\n",

    "Night thoughts:\n"
    "    My heart beats with anxious quiver,\n"
    "    I do not know its will.\n",

    "I cannot forget it,\n"
    "    And yet I dare not think.\n",

    "My heart, my heart is heavy,\n"
    "    Yet May shines bright and free.\n",

    "It seemed the sky had softly kissed\n"
    "    The silent earth below.\n",

    "I dreamt I wept in sorrow,\n"
    "    Dreamed you lay in the grave.\n",

    "The world is dumb, the world is blind,\n"
    "    And you, my Germany, lie deep in sleep.\n",

    "I am a German poet,\n"
    "    Well known in German lands.\n",

    "You are like a flower,\n"
    "    So sweet and pure and fair.\n",

    "Love is a flower,\n"
    "    And spring its gentle air.\n",

    "End and beginning touch as one,\n"
    "    And in the night begins the day.\n",

    "A single fir-tree, lonely,\n"
    "    On a northern mountain height,\n"
    "Sleeps in a white blanket,\n"
    "    Draped in snow and ice.\n",

    "His dreams are of a palm-tree,\n"
    "    Who, far in eastern lands,\n"
    "Weeps, all alone and silent,\n"
    "    Among the burning sands.\n",

    "There lies the heat of summer\n"
    "    On your cheek's lovely art:\n"
    "There lies the cold of winter\n"
    "    Within your little heart.\n",

    "I don't believe in Heaven,\n"
    "    Whose peace the preacher cites:\n"
    "I only trust your eyes now,\n"
    "    They're my heavenly lights.\n",

    "Over my bed rises a tree,\n"
    "    In which the young nightingale sings;\n"
    "She sings of nothing but love,\n"
    "     I hear it even in my dreams.\n",

    "I'll cut my soul in pieces,\n"
    "    And breathe half into you,\n"
    "And hug you: we must be, yes,\n"
    "    One soul and body too.\n",

    "I don't know what it could mean,\n"
    "    Or why I'm so sad: I find,\n"
    "A fairy-tale, from times unseen,\n"
    "    Won't vanish from my mind.\n",

    "The darkness glows, I'm drowning,\n"
    "    Day's tired me with light.\n",

    "You mustn't speak of Germany, to me -\n"
    "    I just can't stand it - I have my reasons.\n",

    "And my little cat sits near me\n"
    "    Warms its paws beside the coals,\n"
    "While the flames are flickering, weaving\n"
    "    Brave imaginings in my soul.\n",

    "Not a Mass will be sung then,\n"
    "    Not a Kaddish will be said,\n"
    "Nothing sung, and nothing spoken,\n"
    "    On the day when I am dead.\n",

    "Now, when I'm wretched and I'm dying,\n"
    "    Now, when my grave's already aired,\n"
    "Often in memory, painful, mocking,\n"
    "    The scent of flowers I scorned is there.\n",

    "Sleep is good: and Death is better, yet\n"
    "    Surely never to have been born is best.\n",

    "It has died in me, as it must,\n"
    "Every idle, earthly lust\n",

    "Down my cheeks run tears all burning,\n"
    "    Silently, unceasingly;\n"
    "But my bosom's fiery yearning\n"
    "    Quench'ed by tears can never be.\n",

    "Unknown sorrows, unknown anguish\n"
    "    Toss me wildly to and fro,\n"
    "And I pine away and languish,\n"
    "    Tortured by an unknown glow.\n",

    "I have borne it for years, with a heart fit to break,\n"
    "    But no longer can bear with the pain;\n"
    "So pack up my bundle, my pilgrim's staff take,\n"
    "    And start on my travels again.\n",

    "When in sorrow, they dare not show it,\n"
    "    However mournful their mood,\n"
    "For the swan, like the soul of the poet,\n"
    "    By the dull world is ill understood.\n",

    "They sail along, and a ringing\n"
    "    Sweet melody rises on high,\n"
    "And when the swans begin singing,\n"
    "    They presently must die.\n",

    "Cholent, light direct from heaven,\n"
    "    Daughter of Elysium!\n"
    "Thus would Schiller's Ode have sounded\n"
    "    Had he ever tasted cholent\n",

    "First, I thought, almost despairing,\n"
    "    This must crush my spirit now;\n"
    "Yet I bore it, and am bearing-\n"
    "    Only do not ask me how.\n",

    "But ah! in Mammon's smiles I ne'er had part,\n"
    "    For I have follow'd thee alone, alas!\n"
    "Thee, Poetry, most thankless, breadless art!\n",

    "She sings of love and love's sorrows as well,\n"
    "    She sings of smiling and aching,\n"
    "She sadly exults, she joyfully sobs,\n"
    "    Forgotten visions awaking.\n",

    "Sleepless and oppress'd with sorrow,\n"
    "    All night long I lie\n"
    "Dreaming, half asleep; the morrow\n"
    "    Sadly wander I.\n",

    "Sweet love, lay thy hand on my heart, and tell\n"
    "    If thou hearest the knocks in that narrow cell?\n"
    "There dwells there a carpenter, cunning is he,\n"
    "    And slily he's hewing a coffin for me.\n",

    "And my limbs, in wanderings dreary,\n"
    "    Sadly drag I, full of gloom,\n"
    "Till I lay my head all weary\n"
    "    In a chilly distant tomb.\n",

    "Blood-spring, from mine eyes 'gin running,\n"
    "    Blood-spring, from my body flow,\n"
    "So that I then, with my hot blood,\n"
    "    May write down my tale of woe.\n",

    "With a fond and kindly greeting,\n"
    "    Lure me those deep waters bright,\n"
    "Yet I know their smoothness cheating\n"
    "    Hides beneath it death and night.\n",

    "But the merry song soon ceases,\n"
    "    Sadly rustle leaf and tree,\n"
    "When he, while his grief increases,\n"
    "    Nears the forest mournfully.\n",

    "But the merry song soon ceases,\n"
    "    Sadly rustle leaf and tree,\n"
    "When he, while his grief increases,\n"
    "    Nears the forest mournfully.\n",

    "As he is of his love bereft,\n"
    "    The grave's the best place that is left,\n"
    "Where he his aching heart may lay,\n"
    "    And sleep until the Judgment Day.\n",

    "I leaning stood against the mast,\n"
    "    And told each wave of ocean;\n"
    "Farewell, my beauteous fatherland!\n"
    "    My bark, how swift thy motion.\n",

    "At evening's silent, melancholy hour,\n"
    "   Long buried songs around me take their place,\n"
    "   And burning tears course swiftly down my face,\n"
    "And my old heart-wounds bleed with greater power.\n",

    "The stars in yonder heavens\n"
    "    Immovably have stood\n"
    "For thousands of years, regarding\n"
    "    Each other in sad loving mood.\n",

    "They speak a mysterious language\n"
    "    That's rich and sweet to the ear;\n"
    "Yet no philologist living\n"
    "    Can make its meaning clear.\n",

    "The lotos flower is troubled\n"
    "    At the sun's resplendent light\n"
    "With sunken head and sadly\n"
    "    She dreamily waits for the night.\n",

    "If knew the nightingales only\n"
    "    That I'm so mournful and sad,\n"
    "They would cheer my misery lonely\n"
    "    With their notes so tuneful and glad.\n",

    "\n" 
};


char* get_poem(){
    srand(time(NULL));
    int random = rand() % NUM_POEMS;
    return heine_db[random];
}


// int main(){
//     /* count poems, if heinebase is updated*/
//     int i = 0;
//     while(strcmp(heine_db[i+1], "\n") != 0) i++;
//     printf("number of poems: %d\n", i);
//     return 0;
// }
