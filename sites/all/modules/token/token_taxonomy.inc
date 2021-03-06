<?php
// $Id: token_taxonomy.inc,v 1.1.2.4 2007/10/16 14:37:59 greggles Exp $

/**
 * Implementation of hook_token_values()
 */
function taxonomy_token_values($type, $object = NULL, $options = array()) {
  $values = array();
  switch ($type) {
    case 'taxonomy':
      $category = $object;
      
      $vid = $category->vid;
      $vocabulary = taxonomy_get_vocabulary($vid);
      $values['vid'] = $vid;
      $values['vocab'] = check_plain($vocabulary->name);
      $values['cat'] = check_plain($category->name);
      $values['tid'] = $category->tid;
      $values['vocab-raw'] = $vocabulary->name;
      $values['cat-raw'] = $category->name;

      break;
  }
  return $values;
}

/**
 * Implementation of hook_token_list()
 */
function taxonomy_token_list($type = 'all') {
  if ($type == 'taxonomy' || $type == 'all') {
    $tokens['taxonomy']['vid'] = t("The id number of the category's parent vocabulary.");
    $tokens['taxonomy']['vocab'] = t("The vocabulary that the page's first category belongs to.");
    $tokens['taxonomy']['cat'] = t('The name of the category.');
    $tokens['taxonomy']['tid'] = t('The id number of the category.');
    $tokens['taxonomy']['vocab-raw'] = t("The unfiltered vocabulary that the page's first category belongs to. WARNING - raw user input.");
    $tokens['taxonomy']['cat-raw'] = t('The unfiltered name of the category. WARNING - raw user input.');

    return $tokens;
  }
}