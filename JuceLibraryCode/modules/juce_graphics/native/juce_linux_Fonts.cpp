/*
  ==============================================================================

   This file is part of the JUCE library - "Jules' Utility Class Extensions"
   Copyright 2004-11 by Raw Material Software Ltd.

  ------------------------------------------------------------------------------

   JUCE can be redistributed and/or modified under the terms of the GNU General
   Public License (Version 2), as published by the Free Software Foundation.
   A copy of the license is included in the JUCE distribution, or can be found
   online at www.gnu.org/licenses.

   JUCE is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
   A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

  ------------------------------------------------------------------------------

   To release a closed-source product which uses JUCE, commercial licenses are
   available: visit www.rawmaterialsoftware.com/juce for more information.

  ==============================================================================
*/

StringArray FTTypefaceList::getDefaultFontDirectories()
{
    StringArray fontDirs;

    fontDirs.addTokens (CharPointer_UTF8 (getenv ("JUCE_FONT_PATH")), ";,", String::empty);
    fontDirs.removeEmptyStrings (true);

    if (fontDirs.size() == 0)
    {
        const ScopedPointer<XmlElement> fontsInfo (XmlDocument::parse (File ("/etc/fonts/fonts.conf")));

        if (fontsInfo != nullptr)
        {
            forEachXmlChildElementWithTagName (*fontsInfo, e, "dir")
            {
                String fontPath (e->getAllSubText().trim());

                if (fontPath.isNotEmpty())
                {
                    if (e->getStringAttribute ("prefix") == "xdg")
                    {
                        String xdgDataHome (SystemStats::getEnvironmentVariable ("XDG_DATA_HOME", String::empty));

                        if (xdgDataHome.trimStart().isEmpty())
                            xdgDataHome = "~/.local/share";

                        fontPath = File (xdgDataHome).getChildFile (fontPath).getFullPathName();
                    }

                    fontDirs.add (fontPath);
                }
            }
        }
    }

    if (fontDirs.size() == 0)
        fontDirs.add ("/usr/X11R6/lib/X11/fonts");

    fontDirs.removeDuplicates (false);
    return fontDirs;
}

Typeface::Ptr Typeface::createSystemTypefaceFor (const Font& font)
{
    return new FreeTypeTypeface (font);
}

void Typeface::scanFolderForFonts (const File& folder)
{
    FTTypefaceList::getInstance()->scanFontPaths (StringArray (folder.getFullPathName()));
}

StringArray Font::findAllTypefaceNames()
{
    return FTTypefaceList::getInstance()->findAllFamilyNames();
}

StringArray Font::findAllTypefaceStyles (const String& family)
{
    return FTTypefaceList::getInstance()->findAllTypefaceStyles (family);
}

bool TextLayout::createNativeLayout (const AttributedString&)
{
    return false;
}

//==============================================================================
struct DefaultFontNames
{
    DefaultFontNames()
        : defaultSans  (getDefaultSansSerifFontName()),
          defaultSerif (getDefaultSerifFontName()),
          defaultFixed (getDefaultMonospacedFontName())
    {
    }

    String getRealFontName (const String& faceName) const
    {
        if (faceName == Font::getDefaultSansSerifFontName())    return defaultSans;
        if (faceName == Font::getDefaultSerifFontName())        return defaultSerif;
        if (faceName == Font::getDefaultMonospacedFontName())   return defaultFixed;

        return faceName;
    }

    String defaultSans, defaultSerif, defaultFixed;

private:
    static String pickBestFont (const StringArray& names, const char* const* choicesArray)
    {
        const StringArray choices (choicesArray);

        for (int j = 0; j < choices.size(); ++j)
            if (names.contains (choices[j], true))
                return choices[j];

        for (int j = 0; j < choices.size(); ++j)
            for (int i = 0; i < names.size(); ++i)
                if (names[i].startsWithIgnoreCase (choices[j]))
                    return names[i];

        for (int j = 0; j < choices.size(); ++j)
            for (int i = 0; i < names.size(); ++i)
                if (names[i].containsIgnoreCase (choices[j]))
                    return names[i];

        return names[0];
    }

    static String getDefaultSansSerifFontName()
    {
        StringArray allFonts;
        FTTypefaceList::getInstance()->getSansSerifNames (allFonts);

        const char* targets[] = { "Verdana", "Bitstream Vera Sans", "Luxi Sans",
                                  "Liberation Sans", "DejaVu Sans", "Sans", nullptr };
        return pickBestFont (allFonts, targets);
    }

    static String getDefaultSerifFontName()
    {
        StringArray allFonts;
        FTTypefaceList::getInstance()->getSerifNames (allFonts);

        const char* targets[] = { "Bitstream Vera Serif", "Times", "Nimbus Roman",
                                  "Liberation Serif", "DejaVu Serif", "Serif", nullptr };
        return pickBestFont (allFonts, targets);
    }

    static String getDefaultMonospacedFontName()
    {
        StringArray allFonts;
        FTTypefaceList::getInstance()->getMonospacedNames (allFonts);

        const char* targets[] = { "DejaVu Sans Mono", "Bitstream Vera Sans Mono", "Sans Mono",
                                  "Liberation Mono", "Courier", "DejaVu Mono", "Mono", nullptr };
        return pickBestFont (allFonts, targets);
    }

    JUCE_DECLARE_NON_COPYABLE (DefaultFontNames)
};

Typeface::Ptr Font::getDefaultTypefaceForFont (const Font& font)
{
    static DefaultFontNames defaultNames;

    Font f (font);
    f.setTypefaceName (defaultNames.getRealFontName (font.getTypefaceName()));
    return Typeface::createSystemTypefaceFor (f);
}
