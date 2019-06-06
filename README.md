Menu Editor
===========

Menu Editor enhances the menu editing form with inline text fields for title, path and description, and provides placeholders for new items.

This way, it reduces the number of page visits needed to create a site's menu structure, and eliminates the need for dummy nodes.

Menu editor attempts to unify content creation and menu editing.


Prerequisite
------------

The Menu Editor module requires Backdrop core's Menu module, and the Node creation sub-module requires [X Autoload](https://backdropcms.org/project/xautoload) module.


Installation
------------

- Enable Backdrop core's Menu module.
- Install this module using the official Backdrop CMS instructions at
  https://backdropcms.org/guide/modules
- You should enable the sub-modules, to get the complete feature set.


Features
--------

- Inline text fields for title, path and description: In each row you get inline text fields for title and link path. This means, you don't need to go to a new page any more to edit the title or destination of a menu item!

- Tabindex: The tab index is modified to skip the annoying checkbox fields ("Enabled", "Expanded", "Delete").

- Placeholder items for new content: You can create menu items for yet non-existing content. Instead of a useless dummy link path, you write "<new page>" or "<new post>" or "<new [content type]>", which is internally stored as "node/add/[content type]/mlid/[mlid]". If you visit that link, you get a node creation form that will make the menu item point to the newly created node. Alternatively, you can use <new> as a general purpose "under construction" placeholder. This allows to quickly plan a site structure with the client, without creating dummy nodes.

- Hook for your own placeholders: The placeholders are defined via an implementation of hook_menu_editor_placeholders(). The definition of this hook might change in the future, to allow more flexible placeholder schemes.

- Permissions: menu_editor introduces one new permission per menu, which gives access to the respective menu_editor page (and nothing more). Users with the "administer menu" permission don't need this extra checkbox, they can always edit all menus.

- Path autocomplete: Path Autocomplete for Menu Editor. This allows to fill your menu items with links to existing content more easily.

- Performance / memory: Replaced the weight dropdowns with text fields, similar to Tiny menu editor. The page will still be quite heavy with all the different input fields, but less than it would be if each row has a dropdown with 50 options.


Issues
------

Bugs and Feature requests should be reported in the Issue Queue:
https://github.com/backdrop-contrib/menu_editor/issues


Current Maintainer
------------------

- Attila Vasas (https://github.com/vasasa).


Credits
-------

- Ported to Backdrop CMS by Attila Vasas (https://github.com/vasasa).
- Originally written for Drupal by Andreas Hennings (https://www.drupal.org/u/donquixote).


License
-------

This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.


Screenshot
----------

![Menu Editor screenshot](https://github.com/backdrop-contrib/menu_editor/blob/1.x-1.x/images/screenshot.png)
