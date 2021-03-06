<?php

/**
 * Page callback for node/add/%node_type/mlid/%menu_editor_mlid
 *
 * @param object $type
 * @param array $menu_item
 *
 * @return array|mixed
 */
function me_node_creation_create_node($type, array $menu_item) {
  global $user;

  backdrop_set_title(t('Create @name', array('@name' => $type->name)), PASS_THROUGH);

  $node = entity_create('node', array('type' => $type->type));
  $node->uid = $user->uid;
  $node->name = isset($user->name) ? $user->name : '';
  $node->langcode = LANGUAGE_NONE;
  $node->me_node_creation_menu_item = $menu_item;

  module_load_include('pages.inc', 'node');

  $form = backdrop_get_form($type->type . '_node_form', $node);

  return $form;
}

/**
 * @param array $form
 * @param object $node
 */
function _me_node_creation_form_alter(array &$form, $node) {
  $menu_item = $node->me_node_creation_menu_item;

  unset($form['menu']);

  $mlid_text = $menu_item['mlid'];
  $mlid_path = "admin/structure/menu/item/$mlid_text/edit";
  if ($mlid_router_item = menu_get_item($mlid_path)) {
    if ($mlid_router_item['access']) {
      $mlid_text = l($mlid_text, $mlid_path);
    }
  }

  $txt = t('The created node will be associated with the chosen menu item (!mlid),<br/>with link title "@title"', array(
    '!mlid' => $mlid_text,
    '@title' => $menu_item['link_title'],
  ));
  $txt = "<p>$txt</p>";

  $form['me_node_creation'] = array(
    '#type' => 'markup',
    '#markup' => $txt,
    '#weight' => -20,
  );

  $form['title']['#default_value'] = $menu_item['link_title'];
  // $form['#me_node_creation_menu_item'] = $menu_item;
  // $form['#submit'][] = 'me_node_creation_node_form_submit';
}
