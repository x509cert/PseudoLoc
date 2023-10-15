﻿#include <string>
#include <map>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

std::map<char, const char32_t*> mappings = {
    {'a', U"αäаαаａ𝐚𝑎𝒂𝒶āăâⓐ"},
    {'b', U"βбƀЬьƅ𝐛𝑏𝒃𝒷ⓑ"},
    {'c', U"ςçссϲς𝐜𝑐𝒄𝒸ⓒ⊂ⓒ"},
    {'d', U"δđдԁⅾ𝐝𝑑𝒅𝒹𝓭Ꮷ∂"},
    {'e', U"εëееℯ𝐞𝑒𝒆𝓮℮ēĕê𝑒∈∉"},
    {'f', U"ϝƒ𝒻𝒇𝒻𝓯𝔣𝕗𝖋𝖿"},
    {'g', U"𝓰ğġցℊ𝐠𝑔𝒈𝓰𝔤"},
    {'h', U"ηħнһ𝐡𝒉𝒽𝓱𝔥𝕙"},
    {'i', U"ιïįі𝐢𝑖𝒊𝒾𝓲𝔦īĭî𐒃"},
    {'j', U"ϳĵ𝓳ϳј𝐣𝑗𝒋𝒿𝓳"},
    {'k', U"κķк𝐤𝑘𝒌𝓀𝓴𝔨𝕜"},
    {'l', U"𝓵ļ𝚕ⅼ𝐥𝑙𝒍𝓁𝓵𝔩ł┃└┕┖"},
    {'m', U"𝓂m̃м𝐦𝑚𝒎𝓂𝓶𝔪𝕞"},
    {'n', U"𝕟ńňո𝐧𝑛𝒏𝓃Պ𝓷𝔫ﬡאּ"},
    {'o', U"οöоо𝐨𝑜𝒐𝓸𝔬𝕠ōŏô⊕⊗⊘"},
    {'p', U"ρƥ𝕡р𝐩𝑝𝒑𝓅𝓹𝔭"},
    {'q', U"q̄q̃Ԛ𝐪𝑞𝒒𝓆𝓺𝔮𝕢"},
    {'r', U"ρř𝙧г𝐫𝑟𝒓𝓇𝓻𝔯ŗ"},
    {'s', U"𝓈š𝕤ѕ𝐬𝑠𝒔𝓈𝓼𝔰"},
    {'t', U"τţт𝐭𝑡𝒕𝓉𝓽𝔱𝕥"},
    {'u', U"υü𝙪υ𝐮𝑢𝒖𝓊𝓾𝔲ūŭⓤûﭒ"},
    {'v', U"νv̆𝖛ν𝐯𝑣𝒗𝓋𝓿𝔳"},
    {'w', U"ωŵѡ𝐰𝑤𝒘𝓌𝔀𝔴𝕨Ꮚ"},
    {'x', U"χх𝕩х𝐱𝑥𝒙𝓍𝔁𝔵ⓧ"},
    {'y', U"ψýуу𝐲𝑦𝒚𝓎𝔂𝔶𐐐γ"},
    {'z', U"ζž𝓏ᴢ𝐳𝑧𝒛𝓏𝔃𝔷ⓩ"},
    {'A', U"ΑÄАΑАᎪＡ𝐀𝑨𝒜Ⓐ∀"},
    {'B', U"ΒƁБΒВᏴＢ𝐁𝑩"},
    {'C', U"𝓒ÇСϹСⅭＣ𝐂𝑪𝒞UⒸ"},
    {'D', U"𝔇ÐДᎠⅮＤ𝐃𝑫𝒟𝐷ↁ"},
    {'E', U"ΕËЕΕЕⅬＥ𝐄𝑬ꘓⵥ€∃∑⁅"},
    {'F', U"𝕱Ƒ𝐹ϜϻⅬＦ𝐅𝑭"},
    {'G', U"𝓖Ğ𝙶ԌǤⅫＧ𝐆𝑮𝒢"},
    {'H', U"ΗĦНΗНᎻＨ𝐇𝑯ℍ"},
    {'I', U"ΙÏ𝕀ΙІⅠＩ𝐈𝑰𝐈Ⅰ𐌆"},
    {'J', U"ϳĴ𝘑ϳЈＪ𝐉𝑱𝒥𝐽"},
    {'K', U"ΚĶКΚКᏦＫ𝐊𝑲𝒦"},
    {'L', U"𝐿Ļ𝗟ⅬⅬᏞＬ𝐋𝑳𝒧ԼՆ⌊⌋┃"},
    {'M', U"ΜṀМϺМᎷＭ𝐌𝑴𝒨ᛗ"},
    {'N', U"ΝŃ𝕹ΝＮᏁＮ𝐍𝑵𝒩Ⲡ𐌿ℕᚢ∏"},
    {'O', U"ΟÖОΟОᎾＯ𝐎𝑶𝒪口Ꭴᱛ"},
    {'P', U"ΡƤ𝖯ΡРᏢＰ𝐏𝑷𝒫ℙ"},
    {'Q', U"Q̄Q̃ԚԚＱႳＱ𝐐𝑸𝒬"},
    {'R', U"𝕽Ř𝘙ᎡᎡＲＲ𝐑𝑹"},
    {'S', U"𝗦Š𝓢ЅᏕＳ𝐒𝑺𝒮𝐒ⵢ⎰"},
    {'T', U"ΤŢТΤТᎢＴ𝐓𝑻𝒯"},
    {'U', U"𝔘Ü𝗨ՍＵᏌＵ𝐔𝑼𝒰Մ"},
    {'V', U"ѴṼ𝓥ⅤＶᏙＶ𝐕𝑽𝒱"},
    {'W', U"𝕎ŴѠԜＷᏔＷ𝐖𝑾𝒲"},
    {'X', U"ΧХ𝔛ΧХⅩＸ𝐗𝑿𝒳𝐗ⵝ☓☠"},
    {'Y', U"ΨÝҮҮＹᎩＹ𝐘𝒀𝒴"},
    {'Z', U"ΖŽℤΖＺᏃＺ𝐙𝒁𝒵ℤ☡"},
    {'0', U"０𝟘⓪𝟎𝟘𝟢𝟬𝟶０〇०"},
    {'1', U"１𝟙①𝟏𝟙𝟣𝟭𝟷１١"},
    {'2', U"２𝟚②𝟐𝟚𝟤𝟮𝟸２২೭²"},
    {'3', U"３𝟛③𝟑𝟛𝟥𝟯𝟹３З³"},
    {'4', U"４𝟜④𝟒𝟜𝟦𝟰𝟺４"},
    {'5', U"５𝟝⑤𝟓𝟝𝟧𝟱𝟻５"},
    {'6', U"６𝟞⑥𝟔𝟞𝟨𝟲𝟼６"},
    {'7', U"７𝟟⑦𝟕𝟟𝟩𝟳𝟽７"},
    {'8', U"８𝟠⑧𝟖𝟠𝟪𝟴𝟾８"},
    {'9', U"９𝟡⑨𝟗𝟡𝟫𝟵𝟿９"},
    {',', U"‚٫٬ꓹ‚"},
    {'?', U"‽⁇⁈⁉"},
    {'!', U"‼⁈⁉"},
    {'.', U"•․∗∘‧،．。｡｡"},
    {'"', U"″”“„‟〝＂〟"},
    {'%', U"⁒℅℆‱"},
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
    ss << std::setw(4)        // Ensure at least 8 characters are printed
        << std::setfill('0')   // Fill with leading zeros if needed
        << std::uppercase      // Use uppercase letters
        << std::hex            // Output in hexadecimal format
        << static_cast<uint32_t>(character);  // Convert char32_t to uint32_t
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

int wmain() {

    dumpUnicodeData();

    const char32_t* wszString = U"Hello, World!";
    char32_t wszResult[40]{};

    auto length = std::char_traits<char32_t>::length(wszString);
    for (int i = 0; i < length; i++) {
        char32_t c = wszString[i];
        auto item = mappings.find((char)c);
        wszResult[i] = (item != mappings.end()) ? item->second[0] : c;
    }
}