/*
 *  Vectors with duplicates to test
 * 
 */

#ifndef __TEST_VECTORS_H
#define __TEST_VECTORS_H

#include <string>
#include <vector>

std::vector<std::string> no_dups_vector{"one", "two", "three", "four", "five", "six", "seven", "done"};
std::vector<std::string> no_dups_vector_dups{};

std::vector<std::string> super_short_vector{"one", "one"};
std::vector<std::string> super_short_vector_dups{"one"};

std::vector<std::string> short_vector{"one", "two", "three", "four", "five", "six", "seven", "one", "two", "three", "done"};
std::vector<std::string> short_vector_dups{"one", "two", "three"};

std::vector<std::string> onehundred_vector{
      "hangover's", "pint", "repertoire", "rendezvous's", "Nat's", "actresses", "appellation", "jays", "Wyomingite", "slurping",
      "chemises", "hanging", "falconer", "retires", "trotters", "grumblers", "laxity's", "foe's", "earthiness", "Nantucket's",
      "refurbishment", "junkie's", "Khoisan's", "degrading", "Tamika's", "counteroffer", "mainlining", "modulates", "animator's", "bunch",
      "goaded", "trinity", "eyeteeth", "besieged", "Mona's", "Vietcong", "gerontology", "fleshiest", "Khoisan's", "falconer",
      "Klan", "sophisticates", "Mona's", "earthiness", "clambake's", "wreathed", "repertoire", "excuses", "baptizes", "ousted",
      "prized", "Muhammadans", "twirling", "gamecocks", "glints", "Armani's", "germinating", "Gene's", "curl", "Pompadour",
      "catharsis", "inactivity's", "dual", "Ross's", "sat", "wreathed", "inactivity's", "pint", "ferrous", "refurbishment",
      "overblown", "elongating", "degrading", "Sudetenland", "rendezvous's", "Ned's", "germinating", "misinterprets", "Mohorovicic's", "eyeteeth",
      "August's", "animator's", "wryness's", "scepters", "incendiary's", "chemises", "loved", "Tamera's", "takings", "birthright's",
      "curl", "trajectories", "twirling", "inspect", "repertoire", "dinginess's", "jibed", "loved", "Pompadour", "socialization"
    };

std::vector<std::string> onehundred_vector_dups{
      "curl", "loved", "chemises", "earthiness", "animator's", "Khoisan's", "twirling", "inactivity's", "wreathed", "eyeteeth",
      "pint", "repertoire", "rendezvous's", "refurbishment", "falconer", "germinating", "Pompadour", "Mona's", "degrading"
    };

std::vector<std::string> onethousand_vector{
      "dignitary", "fetus's", "whiffing", "videocassette", "skycap's", "argues", "Glass", "Bartók", "seaboards", "hyperspace",
      "gurgle's", "Mumbai", "hostilities's", "overspecialize", "deed's", "prurient", "snorkelers", "blubbered", "frequency", "nook",
      "worthier", "evangelicals", "digression", "slues", "categorically", "Jocelyn's", "Tanzania", "overcasts", "boutonnières", "conduce",
      "trickster", "bull's", "uprooting", "digression", "constitutionally", "markets", "mainstream's", "harboring", "timepiece", "Plymouth's",
      "Concord", "diehards", "breaded", "bugaboo's", "fermenting", "puzzling", "Olympias", "facilities", "winking", "cuticles",
      "predicament", "fixity's", "mongrels", "concordances", "destination", "Olympias", "permissibly", "issues", "orthographic", "fetishist",
      "resulting", "outwears", "boutonnières", "Adhara's", "emotion's", "literals", "falsifying", "privateer's", "Tanzanian's", "Mbabane",
      "pussyfooting", "fill's", "gainfully", "portability's", "Brad's", "Coy", "newbie's", "slabbed", "quisling", "irateness's",
      "quarantine", "lire", "preconceived", "desisting", "fastens", "piling's", "lice", "outweigh", "recurrences", "bird's",
      "nonuser", "devoid", "whiting's", "anchorwomen", "excitedly", "ploughing", "racier", "expeditors", "guttural's", "maul",
      "bulldog's", "exploitation", "analogy's", "renumber", "invoked", "kindling's", "cleave", "bibles", "disbelieved", "Hardin's",
      "kindred's", "rebels", "waterfowls", "ragtime", "cutters", "gurgle's", "naturalism", "visibly", "cuspid", "tumbrils",
      "slump", "conduce", "dally", "vacates", "funereal", "abstractness", "contrivance", "choppered", "druid", "Anibal",
      "Columbus", "allusive", "orchid", "destination", "Woolite", "goblin", "inviolate", "betrayal", "grounding's", "Spam's",
      "cushy", "funnelled", "slackest", "pilot's", "dirk", "disputatious", "neatly", "Yamoussoukro", "versatility's", "Langland",
      "flacks", "apostate", "close", "limestone", "Kirghiz", "sideburns", "raiment's", "traffic", "routinizes", "Franz's",
      "postmarked", "assassinate", "publishers", "relates", "corsage's", "octettes", "orthopaedist's", "adulthood", "undertows", "motor's",
      "twigging", "consortium's", "shying", "Anacreon", "zestfully", "consults", "Avon", "nubs", "interaction's", "moieties",
      "bustle's", "centigramme", "beginner's", "fiscal's", "gatherers", "abrasive", "Dawn", "monsignori", "helplessly", "footstep",
      "hub", "Crawford's", "sanctuary", "knuckle's", "schoolhouse", "alkaloid's", "flacks", "ballpark", "commonplace's", "Neanderthals",
      "humanitarian", "comically", "Jami's", "contusions", "Marvell's", "Honecker's", "metropolises", "Nd's", "ineffably", "exhaust's",
      "shrubs", "deliverers", "hooey's", "dye's", "denseness's", "bullshitted", "obstetrician", "Tannhäuser's", "stud", "neurologist",
      "firebombing", "disregarding", "datelines", "greenish", "conduction's", "laboring", "biweeklies", "browbeaten", "alphabetize", "fairs",
      "adolescence", "implantation", "Naphtali", "Ecuadorans", "retrospected", "trenches", "evaluated", "heliport's", "depopulation's", "Coptic's",
      "fraternities", "excitedly", "druggists", "sibling", "retrospective", "contemplation's", "Cantor's", "conditions", "chessboards", "T's",
      "fleshly", "hijacking's", "angiosperms", "enchanted", "engulfed", "rolling", "proposing", "Nikki's", "reels", "recitation's",
      "Juliette", "pestilence's", "tithes", "dejection's", "Penney", "assertiveness's", "guiltier", "sufferers", "Debouillet", "catwalk",
      "canyons", "clatter's", "warpaths", "disassembles", "sachem's", "Aquitaine", "Charity's", "honeyed", "pricier", "grizzly",
      "jitterbug", "liturgical", "versatility's", "bobwhite", "jaywalking", "minuting", "nerveless", "fingering", "faucets", "restroom's",
      "Inonu's", "trashier", "chime", "fastens", "dinner", "farming", "President's", "draw", "bullring's", "vegetarian",
      "rabies's", "circumflex", "hurdling", "Frenches", "hankers", "expeditors", "sensibilities", "thinned", "supplicates", "mongrels",
      "woofer's", "remarked", "trusteeship", "dram", "risked", "gracefulness", "mallet's", "mulishly", "zestful", "raising",
      "dinner", "everglade's", "phosphors", "Ci", "deadwood", "wagoner's", "tabooing", "Szilard", "Atari", "litany's",
      "outnumbers", "canonizations", "blurb's", "milepost's", "Riemann's", "cesium's", "surprising", "Faulknerian", "iambic", "sanitizing",
      "join", "cisterns", "lavished", "dunned", "softening", "Nikki's", "skiff's", "exhaust's", "ethereally", "blimp's",
      "cheese's", "toxicity", "cavalcades", "President's", "recessing", "saris", "depopulation's", "wombat", "stroked", "dream's",
      "engulfed", "tumbledown", "unexciting", "sacrifice", "handymen", "premature", "victim's", "Dawn", "bragged", "glorious",
      "reactors", "pronghorn's", "Columbus", "insigne", "eider's", "drugged", "byways", "franchise", "stints", "torment's",
      "fetus's", "perfectionist's", "dilettantes", "contusions", "virile", "slimness's", "sentient", "acceleration", "net's", "smallness's",
      "primmer", "creditor's", "deflected", "explicated", "ingrown", "manual's", "you", "mossier", "polysyllable", "knuckle's",
      "separate", "camping", "somnambulists", "denseness's", "kindred's", "umiaks", "adolescence", "noonday's", "incomparable", "trisecting",
      "slimness's", "rises", "harboring", "apologist's", "contacted", "disfigures", "conduction's", "instructing", "attenuation's", "pentathlon's",
      "sentient", "grizzlies", "permissibly", "Dolly", "railway", "dartboard's", "gratefulness", "kilogram's", "obstructiveness", "allusive",
      "bullshitted", "banshee", "phenobarbital", "Highlander", "sickbed", "you", "pebbling", "dentin", "whiffing", "sultriest",
      "pampering", "Coy", "lovemaking's", "cloudburst", "tabooing", "azure", "Mbabane", "contrasted", "weirder", "Anacreon",
      "faucets", "sensibilities", "Wilma's", "everlasting", "folklore", "deathblow", "gauze's", "Merthiolate's", "nitpicker", "fiords",
      "Pyotr's", "balladeer's", "deregulated", "downswing", "basics", "heartstrings's", "Lego", "studying", "roadkill's", "hub",
      "risk's", "disconsolate", "maven's", "toddled", "flops", "unexciting", "Staten", "minibusses", "army's", "subpoenaed",
      "Ora", "timber's", "afforested", "sigh", "Goddard", "Marine", "mole", "piked", "McQueen", "surrenders",
      "Jainism", "Sahara", "reclaim", "liturgical", "locution's", "deathblow", "shots", "yapped", "marrying", "Gino",
      "inmates", "goatskins", "renditions", "Ramayana", "Robitussin's", "unstops", "ionized", "bareback", "guiltier", "rosining",
      "bark", "coveys", "homegrown", "maracas", "filleted", "keyholes", "maven's", "bigotries", "Rigoberto", "adulthood",
      "saris", "auricle", "Shelly's", "argues", "novella's", "basics", "treasurer's", "Cerberus's", "confederating", "Nottingham",
      "scanted", "traipses", "wormholes", "slabbed", "heartstrings's", "overflows", "lasagna's", "commonplace's", "bide", "rowel",
      "knelling", "skirmish's", "thermal", "desensitization's", "Franz's", "chatterbox's", "shags", "twofold", "Turkmenistan's", "radiate",
      "newlyweds", "stepparent's", "target", "unsteadiness", "Matt", "fisticuffs's", "relieving", "medium's", "schrod's", "insigne",
      "dartboard's", "betakes", "sable's", "multiplying", "festival's", "father", "phonemic", "warble", "Hohokam", "biophysics's",
      "pilot's", "claustrophobia", "ophthalmology", "banshee", "Shevat", "elastic's", "pups", "flank's", "bloodsucker", "hotbed",
      "remarked", "hyperspace", "minibusses", "Himalaya", "Kyle's", "zestfully", "unctions", "Io's", "slushier", "shout",
      "Liverpudlian's", "Shylockian", "effervesce", "sickbed", "Ora", "target", "deicing", "assortments", "marrying", "chicanery",
      "migration", "sheepishness", "snorkelers", "orthopaedist's", "scanted", "arithmetically", "Pyle", "trigonometry's", "stupendously", "fermenting",
      "minding", "purity's", "earnest", "inexpensive", "besides", "educationally", "haiku", "campsite", "listlessly", "priestess's",
      "unction's", "spinal", "insight", "workable", "overcasts", "axing", "inconspicuously", "clatter's", "mobster", "keyholes",
      "trenches", "Boise's", "vacates", "up", "equalizes", "bugaboo's", "medium's", "ascendency", "capsizing", "upward",
      "earnestness's", "exploitation", "inapt", "inconspicuously", "dwindles", "sycamore", "haddocks", "pentathlon's", "friskiness", "operative",
      "militaristic", "deliverers", "warpaths", "Manchuria's", "traducing", "lowing", "Vivaldi", "Bartók", "justly", "Heisman's",
      "illusive", "overheated", "flops", "blah", "wholesome", "giggle", "firebombing", "concordances", "Amelia", "rescind",
      "decolonize", "paralyzing", "sizable", "missilery", "slightly", "Lego", "undertows", "reconnoitering", "phosphorescent", "bloodmobile",
      "Golding", "smooth", "anchorwomen", "smooth", "difficult", "trashier", "rebels", "Donny", "consults", "oilfields",
      "Mosley's", "confirmations", "yapped", "hostilities's", "chatterbox's", "footsies", "balm's", "forest", "lavished", "execution",
      "newlyweds", "lung", "Baptist's", "payload's", "contacted", "treacle", "counterpanes", "inkiest", "overspecialize", "indicator's",
      "footstep", "comedians", "thirties", "lollygagging", "oblong", "eighteenths", "undertaker", "harvests", "Goddard", "fleshly",
      "Aztlan", "lollypop's", "enemy's", "meandering", "spar", "pique's", "reclaim", "roadkill's", "insight", "chatterboxes",
      "octettes", "peer's", "replicated", "python", "shirtwaists", "Heisman's", "cereals", "tricycles", "Kiowa", "forehead",
      "innovated", "scarified", "Chihuahuas", "commemorations", "headmasters", "Barkley's", "threat's", "sangfroid's", "monsignori", "Barbour",
      "trestle's", "kilogram's", "extradite", "Visigoth's", "curiosity's", "harvester's", "potshot's", "roosting", "bandaging", "traipses",
      "disputatious", "key", "hemlocks", "menial", "joule", "Lubbock", "betakes", "heliport's", "destabilize", "wound",
      "Yuan's", "army's", "novella's", "excursions", "Plymouth's", "sophistication", "McQueen", "disparaged", "thirties", "overheated",
      "bullring's", "friskiness", "timepiece", "sloppiest", "lubricator's", "Jocelyn's", "plagiarism", "Swammerdam's", "Ci", "flirts",
      "comedians", "revisit", "disconsolate", "maple's", "Janelle's", "ratification's", "photocopy", "concealment's", "secessionist", "oinked",
      "shots", "protoplasmic", "ineffably", "erythrocyte's", "claustrophobia", "Hamlin's", "matzo's", "relates", "valise's", "bunching",
      "brackish", "Kirghiz's", "rework", "Catherine's", "Ecuadorans", "fraternities", "valise's", "sangfroid's", "draw", "neurologist",
      "lip", "blasphemer's", "conjugations", "irruption", "Yuan's", "Riemann's", "Seinfeld's", "maple's", "jointly", "franchise",
      "strongbox", "newton", "lollygagging", "unstops", "larval", "reissuing", "coveys", "dwindled", "issues", "neuralgic",
      "grieving", "unanimous", "traducing", "lowing", "rewinding", "thawing", "gantlet", "commencements", "contaminated", "cavalcades",
      "unsteadiness", "swallow's", "Conley's", "up", "topographic", "piddle", "utilization's", "blank's", "equalizes", "dispensary",
      "loafer's", "cleave", "bluffing", "Perm", "Seinfeld's", "Senecas", "orchid", "topographic", "Shelly's", "audaciously",
      "millstone's", "tricycles", "aspirate", "blunt", "salivary", "railway", "mortice", "bipolar", "pebbling", "chicanery",
      "geishas", "dormant", "eeriness's", "apples", "neuralgic", "compatibility's", "seedier", "gelatin", "Chihuahuas", "Naphtali",
      "payload's", "aid's", "slushier", "fourteenth", "brokered", "Bogart's", "woodcarving's", "abstrusely", "Janelle's", "purported",
      "bosom", "disengagement's", "silently", "consequence", "goat's", "Boeotia's", "Marine", "stockings", "debates", "erythrocyte's",
      "declined", "navigates", "drivers", "Astana's", "stepson's", "antiperspirant's", "bulldog's", "indispositions", "anxiously", "Szilard",
      "uprooting", "utterances", "unbiassed", "elastic's", "gooks", "irruption", "deicing", "gubernatorial", "T's", "abrasion",
      "Waterford", "realtors", "sloppiest", "evaluated", "keyhole", "starker", "spinal", "knelling", "epitaphs", "stroked",
      "bolder", "inflammatory", "sweeper", "footsies", "arable", "potentiality's", "genuflection's", "drumstick", "Loyd's", "dally",
      "keyhole", "beaned", "hurrying", "counterpanes", "header", "fourteenth", "outplays", "Kenyan", "Weinberg's", "lubricator's",
      "rod's", "maidservants", "Lubbock", "grownups", "crapping", "Aggie", "crabbiest", "Tanzania", "blurb's", "Irishman's",
      "frequency", "shout", "categorically", "windowsill", "plainness", "supercharging", "DDS's", "meager", "creditor's", "implantation",
      "twelve's", "child", "grownups", "dispensary", "uncertainties", "hardtack's", "dimmest", "cauliflowers", "pacts", "museum",
      "ventures", "chronicler's", "excessive", "racier", "egotist's", "corsage's", "detestable", "buttonhole", "ignores", "drumstick"
    };

std::vector<std::string> onethousand_vector_dups{
      "comedians", "neuralgic", "chatterbox's", "pentathlon's", "slabbed", "lubricator's", "sangfroid's", "deliverers", "chicanery", "fourteenth",
      "implantation", "claustrophobia", "allusive", "digression", "insigne", "army's", "harboring", "insight", "Janelle's", "concordances",
      "draw", "drumstick", "creditor's", "yapped", "snorkelers", "hyperspace", "knuckle's", "up", "Naphtali", "sloppiest",
      "fetus's", "slimness's", "thirties", "sentient", "Columbus", "conduce", "Ora", "coveys", "kilogram's", "stroked",
      "flops", "undertows", "dinner", "pebbling", "grownups", "whiffing", "Olympias", "argues", "slushier", "conduction's",
      "T's", "overspecialize", "medium's", "counterpanes", "newlyweds", "vacates", "heliport's", "heartstrings's", "topographic", "pilot's",
      "firebombing", "valise's", "faucets", "fraternities", "knelling", "Tanzania", "kindred's", "excitedly", "Szilard", "Franz's",
      "Coy", "inconspicuously", "warpaths", "unstops", "President's", "boutonnières", "destination", "timepiece", "saris", "anchorwomen",
      "hostilities's", "exhaust's", "lavished", "traducing", "consults", "shots", "frequency", "categorically", "evaluated", "Seinfeld's",
      "cleave", "elastic's", "trenches", "versatility's", "railway", "adulthood", "Shelly's", "uprooting", "expeditors", "gurgle's",
      "Goddard", "remarked", "scanted", "maple's", "cavalcades", "ineffably", "maven's", "spinal", "monsignori", "Marine",
      "footsies", "commonplace's", "octettes", "sickbed", "unexciting", "basics", "keyholes", "equalizes", "blurb's", "mongrels",
      "Jocelyn's", "McQueen", "neurologist", "hub", "overheated", "Riemann's", "adolescence", "Yuan's", "Anacreon", "orchid",
      "roadkill's", "bullring's", "Chihuahuas", "corsage's", "Bartók", "contusions", "racier", "friskiness", "payload's", "Nikki's",
      "betakes", "dartboard's", "contacted", "you", "lowing", "deicing", "sensibilities", "fastens", "permissibly", "traipses",
      "erythrocyte's", "keyhole", "relates", "Lego", "franchise", "fleshly", "disputatious", "bugaboo's", "tricycles", "trashier",
      "guiltier", "depopulation's", "footstep", "marrying", "unsteadiness", "overcasts", "Plymouth's", "irruption", "Ecuadorans", "shout",
      "Heisman's", "tabooing", "lollygagging", "smooth", "clatter's", "engulfed", "banshee", "reclaim", "zestfully", "Ci",
      "denseness's", "fermenting", "dispensary", "minibusses", "deathblow", "Mbabane", "liturgical", "Lubbock", "dally", "rebels",
      "orthopaedist's", "novella's", "flacks", "bulldog's", "issues", "Dawn", "target", "disconsolate", "bullshitted", "exploitation"
    };

#endif