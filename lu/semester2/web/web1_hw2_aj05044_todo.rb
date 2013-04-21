# The BODY element has such properties:
    # background image is taken from http://i.cdn.turner.com/v5cache/TNT/images/series/franklinandbash/franklinandbash_background.jpg
    # the background is centered horizontally and fixed on top of the screen
    # the page has no padding and margin
    # unless specified otherwise, page font is Arial, a sans-serif font; font size is 16px

# Content column
    # The main content is inside a section with ID="main". This section should be 1000px wide and centered using "auto" margin.
    # A box shadow is applied (20px wide black shadow);

# Top part

    # The top part consists of a logo, a information banner and a navigation menu.

    # The logo needs 30px margin from the left side.

    # The banner box properties are:

        # Its height is 210px.
        # Its visual border is 20px high,
            # its color is 20% grey
        # Its background image is http://i.cdn.turner.com/v5cache/TNT/Images/i84/fb_hdr_btsstrangebrew2_1000x250.jpg
        # Its padding from top and left side is 40px

        # There are H1 and H2 headings inside the banner box.

            # The color of H1 heading is #005BD0,
            # its font size is 45px.
            # The letters are capitalized automatically.
            # This heading has no paddings or margins.

            # H2 font size is 18px.

        # There is a hyperlink inside the banner box.
            # There is no underline for the hyperlink.
            # Its color is #005BD0.
            # The link is show in bold font.
            # When visited, the link is shown in #999999.

    # Menu part (element with ID= "topmenu") is a list that is show as a horizontal menu.

        # The UL element has no padding or margin.
        # The background color is 20% grey.
        # "overflow:auto" is used to avoid "0 height" problem.
        # The menu items (LI elements) are
            # floating on the left side
            # line height is 30 pixels
            # left margin is 20 pixels


# The central part of the page is an "article" element.
    # This element has 15px padding
    # and a white background.

# Aside

    # There is an aside of the central part.
        # Its width is 300px and
        # it floats on the right side.
        # However, the DIV element with class "chapter"
            # has a right margin of 310 pixels.

        # H3 headings in the aside
            # have color of #005BD0,
            # their size is 14px.
        # The H2 heading next to them is #8F866A

    # Create a selector that picks both the elements with ID="legal-advice" and with ID="man-cave".
    # Make their height be 100px
    # and background image centered horizontally and vertically.

    # Now create separate selectors for each of these elements
    # and set the background of #legal-advice to http://i.cdn.turner.com/v5cache/TNT/Images/i82/fb_explore_notsolegal_300x169.jpg
    # and background of #man-cave to  http://i.cdn.turner.com/v5cache/TNT/Images/i82/fb_explore_mancave_300x169.jpg

# Footer
    # At the end of the page there is a footer element.
    # Its width is 1000 pixels.
    # Its background color is #999999,
    # it has centered 12px Arial text.
    # The footer has a double top border (3px, color #555).
    # Paragraphs inside the footer have no margin/padding.

Submission
    Check that the CSS validator finds no errors in your document: http://jigsaw.w3.org/css-validator/

Submit only the "bash.css" file.