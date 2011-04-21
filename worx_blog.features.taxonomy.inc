<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function worx_blog_taxonomy_default_vocabularies() {
  return array(
    'worx_blog_categories' => array(
      'name' => 'Categories',
      'description' => '',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '0',
      'multiple' => '0',
      'required' => '0',
      'tags' => '1',
      'module' => 'features_worx_blog_categories',
      'weight' => '0',
      'nodes' => array(
        'blog' => 'blog',
      ),
    ),
  );
}
