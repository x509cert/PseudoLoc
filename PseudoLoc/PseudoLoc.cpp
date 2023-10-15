#include <string>
#include <map>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <locale>
#include <codecvt>
#include <stdio.h>
#include <cstdlib>

const std::map<char, const char32_t*> mappings = {
    {'a', U"@αäаαаａ𝐚𝑎𝒂𝒶āăâⓐɐд"},
    {'b', U"βбƀЬьƅ𝐛𝑏𝒃𝒷ⓑϦ"},
    {'c', U"¢ↄссϲς𝐜𝑐𝒄𝒸ⓒ⊂ⓒҁ"},
    {'d', U"ⅆδđдԁⅾ𝐝𝑑𝒅𝒹𝓭Ꮷ∂"},
    {'e', U"ョ℮εëееℯ𝐞𝑒𝒆𝓮℮ēĕê𝑒∈∉ȩɜөӭ૬"},
    {'f', U"🝡ϝƒ𝒻𝒇𝒻𝓯𝔣𝕗𝖋𝖿ḟ"},
    {'g', U"𝓰ğġցℊ𝐠𝑔𝒈𝓰𝔤"},
    {'h', U"♄ħнһ𝐡𝒉𝒽𝓱𝔥𝕙ȟ"},
    {'i', U"וֹ¡㆐ⅈιïįі𝐢𝑖𝒊𝒾𝓲𝔦īĭî𐒃"},
    {'j', U"ⅉϳĵ𝓳ϳј𝐣𝑗𝒋𝒿𝓳"},
    {'k', U"κķк𝐤𝑘𝒌𝓀𝓴𝔨𝕜"},
    {'l', U"𐑗𝓵𐑐ļ𝚕ⅼ𝐥𝑙𝒍𝓁𝓵𝔩ł┃└┕┖"},
    {'m', U"𝓂m̃м𝐦𝑚𝒎𝓂𝓶𝔪𝕞ՠܗ"},
    {'n', U"ƞη𝕟ńňո𝐧𝑛𝒏𝓃Պ𝓷𝔫ﬡאּͷл"},
    {'o', U"סּ¤𝒪㉧οöоо𝐨𝑜𝒐𝓸𝔬𝕠ōŏô⊕⊗⊘⌀ố"},
    {'p', U"𝒫℗𐑜⍴ρƥ𝕡р𝐩𝑝𝒑𝓅𝓹𝔭Þ"},
    {'q', U"q̄q̃Ԛ𝐪𝑞𝒒𝓆𝓺𝔮𝕢ɋ"},
    {'r', U"ρř𝙧г𝐫𝑟𝒓𝓇𝓻𝔯ŗ"},
    {'s', U"Ƨ𝓈š𝕤ѕ𝐬𝑠𝒔𝓈𝓼𝔰ș"},
    {'t', U"㆜τţт𝐭𝑡𝒕𝓉𝓽𝔱𝕥†ナէ"},
    {'u', U"μυü𝙪υ𝐮𝑢𝒖𝓊𝓾𝔲ūŭⓤûﭒ৺"},
    {'v', U"νv̆𝖛ν𝐯𝑣𝒗𝓋𝓿𝔳ѵ"},
    {'w', U"ωשׂ⍵ωŵѡ𝐰𝑤𝒘𝓌𝔀𝔴𝕨Ꮚẅώա"},
    {'x', U"⨯✘χх𝕩х𝐱𝑥𝒙𝓍𝔁𝔵ⓧϗжӽ"},
    {'y', U"ψýуу𝐲𝑦𝒚𝓎𝔂⒴𝔶𐐐γ¥ỿӳ"},
    {'z', U"ζž𝓏ᴢ𝐳𝑧𝒛𝓏𝔃𝔷ⓩƶ"},
  
    {'A', U"₳ΑÄАΑАᎪＡ𝐀𝑨𝒜Ⓐ∀ĄД"},
    {'B', U"฿฿ΒƁБΒВᏴＢ𝐁𝑩"},
    {'C', U"🌜︎ⒸC∁ㄈ₡₵𝓒ÇСϹСⅭＣ𝐂𝑪𝒞UⒸҀ"},
    {'D', U"ⅅ𝔇ÐДᎠⅮＤ𝐃𝑫𝒟𝐷ↁ"},
    {'E', U"ΞعヨΕËЕΕЕⅬＥ𝐄𝑬ꘓⵥ€∃∑⁅Έξ"},
    {'F', U"𝔽𝕱Ƒ𝐹ϜϻⅬＦ𝐅𝑭₣"},
    {'G', U"₲⅁𝓖Ğ𝙶ԌǤⅫＧ𝐆𝑮𝒢"},
    {'H', U"ΗĦНΗНᎻＨ𝐇𝑯ℍȞ"},
    {'I', U"إⒾΙÏ𝕀ΙⅠＩ𝐈𝑰𝐈Ⅰ𐌆Ì"},
    {'J', U"للϳĴ𝘑ϳЈＪ𝐉𝑱𝒥𝐽ਹ"},
    {'K', U"𝕂ΚĶКΚКᏦＫ𝐊𝑲𝒦₭Ϗ"},
    {'L', U"𝐿Ļ𝗟ⅬⅬᏞＬ𝐋𝑳𝒧ԼՆ⌊⌋┃"},
    {'M', U"ΜṀМϺМᎷＭ𝐌𝑴𝒨ᛗ௱ന"},
    {'N', U"₦ΝŃ𝕹ΝＮᏁＮ𝐍𝑵𝒩Ⲡ𐌿ℕᚢ∏ÑͶர౧"},
    {'O', U"🌑︎🌚︎🌝︎⦶θ〄ΟÖОΟОᎾＯ𝐎𝑶𝒪口Ꭴᱛ⊛Ⓞ◯ÔỒѺ੦ఠර"},
    {'P', U"¶₱ΡƤ𝖯ΡРᏢＰ𝐏𝑷𝒫ℙ"},
    {'Q', U"Q̄Q̃ԚＱႳＱ𝐐𝑸𝒬Ɋ"},
    {'R', U"𝕽Ř𝘙ᎡᎡＲＲ𝐑𝑹"},
    {'S', U"∫§𝗦Š𝓢ЅᏕＳ𝐒𝑺𝒮𝐒ⵢ⎰"},
    {'T', U"₸ㄒㅜ┬╤ΤŢТΤТᎢＴ𝐓𝑻𝒯₸ፕ"},
    {'U', U"☋⛎︎℧𝔘Ü𝗨ՍＵᏌＵ𝐔𝑼𝒰ՄƱƲ"},
    {'V', U"ѴṼ𝓥ⅤＶᏙＶ𝐕𝑽𝒱۷"},
    {'W', U"𝕎ŴѠԜＷᏔＷ𝐖𝑾𝒲൰"},
    {'X', U"╳ΧХ𝔛ΧХⅩＸ𝐗𝑿𝒳𝐗ⵝ☓☠χ"},
    {'Y', U"ΨÝҮҮＹᎩＹ𝐘𝒀𝒴♆부ƔƲ"},
    {'Z', U"ΖŽℤΖＺᏃＺ𝐙𝒁𝒵ℤ☡Ƶ"},
 
    {'0', U"0０𝟘⓪𝟎𝟘𝟢𝟬𝟶０〇०"},
    {'1', U"𐑑⒈１𝟙①𝟏𝟙𝟣𝟭𝟷１١"},
    {'2', U"շ２𝟚②𝟐𝟚𝟤𝟮𝟸２২೭²"},
    {'3', U"⒊З３𝟛③𝟑𝟛𝟥𝟯𝟹３ЗǮ³३"},
    {'4', U"４⑷𝟜④𝟒𝟜𝟦𝟰𝟺４"},
    {'5', U"５𝟝⑤𝟓𝟝𝟧𝟱𝟻５"},
    {'6', U"６𝟞⑥𝟔𝟞𝟨𝟲𝟼６"},
    {'7', U"７𝟟⑦𝟕𝟟𝟩𝟳𝟽７"},
    {'8', U"８𝟠⑧𝟖𝟠𝟪𝟴𝟾８"},
    {'9', U"９𝟡⑨𝟗𝟡𝟫𝟵𝟿９"},

    {',', U"‚٫٬ꓹ‚"},
    {'?', U"‽⁇⁈⁉¿⚳"},
    {'!', U"‼⁈⁉"},
    {'.', U"•․∗∘‧،．。｡｡"},
    {'"', U"″”“„‟〝＂〟"},
    {'%', U"⁒℅℆‱"},
    {':', U"׃"},
    {'*', U"✶🞶★❈⁂"},
    {' ', U"␣       "}, // various 'spaces' 
    {'\'', U"′‘’｀"}
};

std::map<std::string, std::string> readData(const std::string& filename) {
    std::map<std::string, std::string> dataMap;
    std::ifstream infile(filename);

    if (!infile.is_open()) {
        std::cerr << "Could not open the file: " << filename << std::endl;
        return dataMap;
    }

    std::string line;
    size_t count{};
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string key, value;

        if (std::getline(iss, key, ';') && std::getline(iss, value, ';')) {            
            dataMap[key] = value;
        }
        else {
            std::cerr << "Malformed line: " << line << std::endl;
        }

        if (++count % 100 == 0)
            printf("\r%zd lines read from unicode file.", count);
    }

    infile.close();
    return dataMap;
}

std::string toUppercaseHexString(char32_t character) {
    std::stringstream ss;
    ss << std::setw(4)         // Ensure at least 4 characters are printed
        << std::setfill('0')   // Fill with leading zeros if needed
        << std::uppercase      // Use uppercase letters
        << std::hex            // Output in hexadecimal format
        << static_cast<uint32_t>(character);  
    return ss.str();
}

void dumpUnicodeData() {

    // dump all the Unicode pseudoloc data from the map
    auto unicodeData = readData("UnicodeData.txt");
    for (const auto& [key, value] : mappings) {
        std::cout << key << std::endl;
        auto length = std::char_traits<char32_t>::length(value);
        for (int i = 0; i < length; i++) {
            auto lookup = toUppercaseHexString(value[i]);
            auto item = unicodeData.find(lookup);
            if (item != unicodeData.end())
                std::cout << "\t" << lookup << "\t" << item->second << std::endl;
        }
    }
}

void PseudoLocString(const char32_t* wszString, char32_t* wszResult) {

    auto length = std::char_traits<char32_t>::length(wszString);
    for (int i = 0; i < length; i++) {
        char32_t c = wszString[i];
        auto item = mappings.find((char)c);
        auto idx = std::rand() % std::char_traits<char32_t>::length(item->second);
        auto ch = item->second[idx];
        wszResult[i] = (item != mappings.end()) ? ch : c;
    }
}

int wmain() {

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // this displays all the unicode mapping details, 
    // this is so you can see what a letter might map onto
    //dumpUnicodeData();

    const char32_t* wszString = U"Hello, World!";
    char32_t wszResult[40]{};

    PseudoLocString(wszString, wszResult);
}